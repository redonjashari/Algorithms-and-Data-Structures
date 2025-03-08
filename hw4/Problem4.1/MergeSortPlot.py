# CH-231-A
# hw4
# Redon Jashari
# RJASHARI@constructor.university

import matplotlib.pyplot as plt
import numpy as np

### Times here are for a fixed sized vector of 1000 elements

#numpy array that holds Best Case time computations
bestCase = np.array([ 
    975, 893, 435, 155, 141, 185, 121, 105, 106, 
    105, 176, 105, 149, 95, 80, 80, 79, 80, 80, 
    79, 80, 79, 93, 80, 80, 80, 100, 137, 84, 92, 
    81, 89, 110, 71, 71, 89, 67, 87, 66, 157, 108, 
    90, 67, 93, 64, 105, 66, 65
])

#numpy array that holds Worst Case time computations
worstCase = np.array([
    199, 194, 144, 144, 191, 136, 118, 117, 117, 
    136, 185, 117, 142, 122, 143, 141, 204, 138, 
    212, 190, 166, 139, 206, 144, 125, 124, 187, 
    144, 164, 201, 146, 221, 142, 146, 141, 141, 
    211, 141, 142, 141, 141, 141, 156, 138, 138, 
    138, 138, 197
])

#numpy array that holds Average Case time computations
averageCase = np.array([
    237, 234, 188, 217, 211, 186, 174, 158, 223, 
    158, 159, 158, 219, 224, 187, 151, 168, 173, 
    240, 147, 144, 146, 145, 145, 242, 166, 146, 
    144, 144, 204, 135, 133, 133, 134, 132, 209, 
    177, 138, 136, 134, 137, 193, 136, 138, 137, 
    192, 140, 206
])

#plot the three lines
plt.plot(bestCase, label="Best Case")
plt.plot(worstCase, label="Worst Case")
plt.plot(averageCase, label="Average Case")

#add some lables, a title, and a legend
plt.xlabel("K-Value")
plt.ylabel("Time in Microseconds")
plt.title("Compuation Time for N=1000")
plt.legend()
plt.show()