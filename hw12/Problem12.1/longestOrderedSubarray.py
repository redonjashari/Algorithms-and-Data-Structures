# CH-231-A
# hw12
# Redon Jashari
# RJASHARI@constructor.university

def longest_increasing_subsequence(arr):
    n = len(arr)
    if n == 0:
        return []
    #dp[i] = length of LIS ending at i
    dp = [1] * n
    #prev[i] = index of previous element in LIS ending at i
    prev = [-1] * n

    max_len = 1
    max_end = 0

    for i in range(n):
        for j in range(i):
            if arr[j] < arr[i] and dp[j] + 1 > dp[i]:
                dp[i] = dp[j] + 1
                prev[i] = j
        if dp[i] > max_len:
            max_len = dp[i]
            max_end = i

    #reconstruct LIS
    lis = []
    idx = max_end
    while idx != -1:
        lis.append(arr[idx])
        idx = prev[idx]
    lis.reverse()
    return lis

if __name__ == "__main__":
    import sys
    for line in sys.stdin:
        data = line.strip().split()
        if not data:
            continue
        try:
            arr = list(map(int, data))
        except ValueError:
            continue
        lis = longest_increasing_subsequence(arr)
        print(' '.join(map(str, lis)))
