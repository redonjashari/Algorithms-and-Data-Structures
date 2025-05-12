# CH-231-A
# hw13
# Redon Jashari
# RJASHARI@constructor.university

import math
from typing import List, Optional

def dijkstra(adj: List[List[Optional[float]]], src: int) -> List[float]:
    """
    Compute shortest path distances from src to all nodes in a non negative weighted
    graph given by adj-matrix.  adj[u][v] is the weight (time) from u->v, or None
    if there's no direct edge.
    Returns a list dist[] where dist[v] is the shortest time from src to v (or math.inf).
    """
    n = len(adj)
    dist = [math.inf] * n
    visited = [False] * n

    dist[src] = 0
    for _ in range(n):
        # pick the unvisited node u with smallest dist[u]
        u = min(
            (d, i) for i, d in enumerate(dist) if not visited[i]
        )[1]
        if dist[u] == math.inf:
            break
        visited[u] = True

        # relax all edges u -> v
        for v, w in enumerate(adj[u]):
            if w is not None and not visited[v]:
                alt = dist[u] + w
                if alt < dist[v]:
                    dist[v] = alt

    return dist

def find_meetup_city(
    adj_matrix: List[List[Optional[float]]],
    your_city: int,
    friend_city: int
) -> Optional[int]:
    dp = dijkstra(adj_matrix, your_city)
    dq = dijkstra(adj_matrix, friend_city)

    best_city = None
    best_time = math.inf

    for m in range(len(adj_matrix)):
        arrival = max(dp[m], dq[m])
        if arrival < best_time:
            best_time = arrival
            best_city = m

    #if best_time is still infinite, there's no mutual reachable city
    return best_city if best_time < math.inf else None
