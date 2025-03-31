def msd_radix_sort(arr):
    if not arr:
        return arr
    
    max_num = max(arr)
    max_length = len(str(max_num))
    
    str_arr = [str(x).zfill(max_length) for x in arr]
    
    def msd_sort(lst, d):
        if len(lst) <= 1 or d >= max_length:
            return lst
        
        buckets = [[] for _ in range(10)]
        
        for s in lst:
            digit = int(s[d])
            buckets[digit].append(s)
        
        result = []
        for bucket in buckets:
            result.extend(msd_sort(bucket, d + 1))
        return result
    
    sorted_str_arr = msd_sort(str_arr, 0)
    
    sorted_arr = [int(s) for s in sorted_str_arr]
    return sorted_arr

if __name__ == "__main__":
    numbers = [170, 45, 75, 90, 802, 24, 2, 66]
    print("Original list:", numbers)
    sorted_numbers = msd_radix_sort(numbers)
    print("Sorted list:  ", sorted_numbers)
