# CH-231-A
# hw7
# Redon Jashari
# RJASHARI@constructor.university

import matplotlib.pyplot as plt

time_lomuto = 0.000146004
time_hoare = 0.000131962
time_median = 0.000146785

methods = ["Lomuto", "Hoare", "Median-of-Three"]
times = [time_lomuto, time_hoare, time_median]

plt.figure(figsize=(8, 5))
plt.bar(methods, times, color=['blue', 'green', 'red'])
plt.xlabel("Quicksort Partitioning Methods")
plt.ylabel("Average Execution Time (seconds)")
plt.title("Performance Comparison of Quicksort Variants")
plt.show()