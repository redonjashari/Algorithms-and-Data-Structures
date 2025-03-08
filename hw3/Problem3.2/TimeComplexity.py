# CH-231-A
# hw3
# Redon Jashari
# RJASHARI@constructor.university

import time
from SelectionSort import selection_sort

def measure_time(sort_func, arr):
    start_time = time.time_ns() #used time_ns for more accuracy
    sort_func(arr.copy())
    result = time.time_ns() - start_time
    converted_result = result / (10 ** 9)
    return converted_result
