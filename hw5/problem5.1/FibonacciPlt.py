# CH-231-A
# hw4
# Redon Jashari
# RJASHARI@constructor.university

import matplotlib.pyplot as plt 
import numpy as np

n_values = [0, 1, 2, 3, 4, 5, 6, 8, 10, 13, 16, 20, 25, 32, 40]
recursive_times = [0, 0, 0, 0, 0, 0, 0, 0, 1 , 4, 16, 111, 1264, 31452, 1169491]
bottom_up_times = [0, 0, 3, 0, 0, 0, 0, 0, 0, 0, 0, 1, 1, 9, 2]
closed_form_times = [11, 9, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 3, 0]
matrix_times = [0, 0, 3, 4, 3, 5, 5, 5, 7, 7, 8, 9, 10, 30, 5]

plt.figure(figsize=(10, 6))
plt.plot(n_values, recursive_times, label='Recursive')
plt.plot(n_values, bottom_up_times, label='Bottom-Up')
plt.plot(n_values, closed_form_times, label='Closed-Form')
plt.plot(n_values, matrix_times, label='Matrix')

plt.yscale("log")
plt.xlabel("n")
plt.ylabel("Execution Time (microseconds)")
plt.title("Fibonacci Computation Time Comparison")
plt.legend()
plt.grid(True)
plt.show()