l =  [
    216, 324, 403, 539, 572, 813, 815, 891, 1041, 1307, 
    1489, 1530, 1582, 1599, 1770, 1971, 2094, 2174, 2215, 
    2230, 2316, 2476, 2560, 2772, 2818, 3098, 3141, 3163, 
    3212, 3561, 3631, 3761, 3789, 3820, 4098, 4145, 4153, 
    4188, 4233, 4290, 4362, 4468, 4603, 4888, 5081, 5162, 
    5197, 5197, 5224, 5266, 5272, 5432, 5859, 5883, 6007, 
    6098, 6127, 6206, 6228, 6416, 6449, 6471, 6546, 6557, 
    6725, 6778, 7262, 7315, 7607, 7653, 7759, 7860, 7874, 
    7924, 7956, 7959, 7981, 8187, 8275, 8320, 8331, 8537, 
    8556, 8613, 8633, 8916, 8919, 8923, 8954, 8962, 8973, 
    9096, 9273, 9372, 9517, 9699, 9765, 9796, 9811, 9951
]
x = 3820

def binary_search(input: list[int], x: int, low: int, high: int):
    # No match is found if ranges intersect
    if (high < low):
        return -1

    # find middle of current range (floored value)
    mid = (low + high) // 2

    # Check if value is found and return its index
    if (input[mid] == x):
        return mid
    
    # Jump to higher section of array if value at current index < x
    if (input[mid] < x):
       return binary_search(l, x, mid + 1, high)

    # Jump to lower section of array if value at current index > x
    if (input[mid] > x):
        return binary_search(l, x, low, mid - 1)
        

index = binary_search(l, x, 0, len(l) - 1)
print(f'Match found at index {index}' if index != -1 else 'No match found')
