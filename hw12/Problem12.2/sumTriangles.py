# CH-231-A
# hw12
# Redon Jashari
# RJASHARI@constructor.university

def max_path_triangle(triangle):
    n = len(triangle)
    if n == 0:
        return 0, []
    #dp[i][j] = max sum to triangle[i][j]
    dp = [[0]*len(row) for row in triangle]
    parent = [[None]*len(row) for row in triangle]

    dp[0][0] = triangle[0][0]
    for i in range(1, n):
        for j in range(len(triangle[i])):
            #two possible parents: (i-1, j-1) or (i-1, j)
            best_sum = -1
            best_parent = None
            if j-1 >= 0:
                if dp[i-1][j-1] > best_sum:
                    best_sum = dp[i-1][j-1]
                    best_parent = (i-1, j-1)
            if j < len(dp[i-1]):
                if dp[i-1][j] > best_sum:
                    best_sum = dp[i-1][j]
                    best_parent = (i-1, j)
            dp[i][j] = best_sum + triangle[i][j]
            parent[i][j] = best_parent
    #find max in last row
    last_row = dp[-1]
    if not last_row:
        return 0, []
    max_sum = max(last_row)
    j = last_row.index(max_sum)
    #reconstruct path
    path = []
    i = n-1
    while True:
        path.append(triangle[i][j])
        p = parent[i][j]
        if p is None:
            break
        i, j = p
    path.reverse()
    return max_sum, path

if __name__ == '__main__':
    import sys

    #read all non-empty lines
    lines = [line.strip() for line in sys.stdin if line.strip()]
    if not lines:
        print("Error: no input", file=sys.stderr)
        sys.exit(1)

    #decide whether the first line is an 'n' or is itself row 0
    first_tok = lines[0].split()
    triangle_lines = None

    #explicit n on first line, and exactly n subsequent rows
    if (len(first_tok) == 1
        and lines[0].isdigit()
        and len(lines) - 1 == int(first_tok[0])):
        n = int(first_tok[0])
        triangle_lines = lines[1:]

    #no explicit n; treat every line as row i (i+1 values on line i)
    else:
        triangle_lines = lines
        n = len(triangle_lines)

    #parse triangle_rows into ints, enforcing row-length = i+1
    triangle = []
    for i, line in enumerate(triangle_lines):
        toks = line.split()
        if len(toks) < i+1:
            print(f"Error: row {i+1} has only {len(toks)} values, but needs {i+1}", file=sys.stderr)
            sys.exit(1)
        try:
            row = list(map(int, toks[: i+1]))
        except ValueError:
            print(f"Error: non-integer on row {i+1}", file=sys.stderr)
            sys.exit(1)
        triangle.append(row)

    #compute and print
    total, path = max_path_triangle(triangle)
    print(total)
    print(' '.join(map(str, path)))


