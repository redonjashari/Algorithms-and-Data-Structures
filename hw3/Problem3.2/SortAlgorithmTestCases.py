# CH-231-A
# hw3
# Redon Jashari
# RJASHARI@constructor.university

import random

def worst_case(n):
    return list(range(n, 0, -1)) 
#Worst case is reverse array

def best_case(n):
    return list(range(1, n + 1))
#Best case is already sorted array

def average_case(n):
    arr = list(range(1, n + 1))
    random.shuffle(arr)
    return arr