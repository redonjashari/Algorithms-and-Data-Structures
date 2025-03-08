# CH-231-A
# hw3
# Redon Jashari
# RJASHARI@constructor.university

import matplotlib.pyplot as plt
from SortAlgorithmTestCases import worst_case, best_case, average_case
from SelectionSort import selection_sort
from TimeComplexity import measure_time

sizes = [10, 20, 30, 40, 50]
times_A, times_B, times_avg = [], [], []
num_test_cases = 10

for n in sizes:
    case_A = worst_case(n)
    case_B = best_case(n)
    avg_case = average_case(n)

    times_A.append(measure_time(selection_sort, case_A))
    times_B.append(measure_time(selection_sort, case_B))

    #20 different test cases for avg time for reliable measurements
    avg_time = sum(measure_time(selection_sort, average_case(n)) for _ in range(20)) / 20
    times_avg.append(avg_time)

plt.plot(sizes, times_A, label="Case A (Worst)")
plt.plot(sizes, times_B, label="Case B (Best)")
plt.plot(sizes, times_avg, label="Average Case")
plt.xlabel("Input Size (n)")
plt.ylabel("Time (seconds)")
plt.legend()
plt.title("Selection Sort Complexity Analysis")
plt.show()
