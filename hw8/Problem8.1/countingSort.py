def counting_sort(arr):
    if not arr:
        return []
    k = max(arr)
    count = [0] * (k + 1)
    for num in arr:
        count[num] += 1
    sorted_arr = []
    for value, cnt in enumerate(count):
        sorted_arr.extend([value] * cnt)
    return sorted_arr

sequence = [9, 1, 6, 7, 6, 2, 1]
sorted_sequence = counting_sort(sequence)
print("Counting Sort Output:", sorted_sequence)
