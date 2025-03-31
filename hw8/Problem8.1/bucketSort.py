def bucket_sort(arr):
    n = len(arr)
    if n == 0:
        return []
    buckets = [[] for _ in range(n)]
    for x in arr:
        index = int(n * x)
        if index == n: 
            index = n - 1
        buckets[index].append(x)
    sorted_arr = []
    for bucket in buckets:
        sorted_bucket = sorted(bucket)
        sorted_arr.extend(sorted_bucket)
    return sorted_arr

sequence_f = [0.9, 0.1, 0.6, 0.7, 0.6, 0.3, 0.1]
sorted_sequence_f = bucket_sort(sequence_f)
print("Bucket Sort Output:", sorted_sequence_f)
