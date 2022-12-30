import random

l = [32, 1, 0, 3, 36, 37, 41, 11, 12, 44, 14, 13, 50, 19, 22, 25, 26]

def bubble_sort(input: list[int]):
    for x in range(0, len(input)):
        for y in range(x, len(input)):
            # Switch bigger value with lower value, aka float (bubble) higher values to the top
            if input[x] > input[y]:
                input[x], input[y] = input[y], input[x]

bubble_sort(l)
print(l)
