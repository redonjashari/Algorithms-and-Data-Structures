# CH-231-A
# hw13
# Redon Jashari
# RJASHARI@constructor.university

import random
from collections import deque
from typing import List, Optional

class PuzzleBoard:
    def __init__(self, board_size: int, fields: Optional[List[List[int]]] = None):
        self.n = board_size
        if fields is None:
            #random values from 1 to n-1
            self.fields = [
                [random.randint(1, board_size-1) for _ in range(board_size)]
                for _ in range(board_size)
            ]
        else:
            if len(fields) != board_size or any(len(row) != board_size for row in fields):
                raise ValueError("fields must be an n×n matrix")
            self.fields = [list(row) for row in fields]

        #player's current position
        self.cur_i = 0
        self.cur_j = 0

    def make_move(self, direction: int) -> bool:
        """
        Direction: 0=up, 1=right, 2=down, 3=left.
        If the move is valid, updates (cur_i,cur_j) and returns True;
        otherwise returns False
        """
        step = self.fields[self.cur_i][self.cur_j]
        di, dj = {0:(-1,0), 1:(0,1), 2:(1,0), 3:(0,-1)}.get(direction, (0,0))
        ni, nj = self.cur_i + di*step, self.cur_j + dj*step

        if 0 <= ni < self.n and 0 <= nj < self.n:
            self.cur_i, self.cur_j = ni, nj
            return True
        else:
            return False

    def get_result(self) -> bool:
        #return True if the player has reached the bottom-right corner
        return (self.cur_i, self.cur_j) == (self.n-1, self.n-1)

    def __str__(self) -> str:
        rows = []
        for i in range(self.n):
            row = []
            for j in range(self.n):
                if (i, j) == (self.cur_i, self.cur_j):
                    row.append(f"P[{self.fields[i][j]}]")
                else:
                    row.append(f" {self.fields[i][j]} ")
            rows.append(" ".join(row))
        return "\n".join(rows)

    def solve(self) -> int:
        #we do the BFS on the graph
        target = (self.n-1, self.n-1)
        seen = [[False]*self.n for _ in range(self.n)]
        q = deque([(0,0)])
        seen[0][0] = True

        while q:
            i, j = q.popleft()
            if (i,j) == target:
                return 1 # if solvable

            step = self.fields[i][j]
            for di, dj in [(-1,0),(0,1),(1,0),(0,-1)]:
                ni, nj = i + di*step, j + dj*step
                if 0 <= ni < self.n and 0 <= nj < self.n and not seen[ni][nj]:
                    seen[ni][nj] = True
                    q.append((ni, nj))

        return -1 #if not solvable
