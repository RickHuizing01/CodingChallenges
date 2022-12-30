package main

import (
	"fmt"
)

func main() {
	slice := []int{
		223, 522, 701, 182, 693, 662, 867, 878, 343, 287, 
		107, 556, 367, 585, 597, 619, 831, 91, 228, 62, 
		111, 871, 841, 514, 471, 696, 805, 858, 34, 190, 
		644, 301, 975, 680, 328, 495, 439, 989, 376, 350, 
		636, 883, 685, 552, 532, 943, 937, 632, 698, 953, 
		548, 227, 140, 109, 564, 89, 683, 549, 766, 157, 
		599, 833, 4, 943, 290, 993, 560, 272, 477, 727, 
		159, 319, 436, 10, 230, 272, 577, 41, 394, 419, 
		151, 923, 565, 949, 971, 394, 713, 492, 127, 862, 
		207, 210, 582, 292, 154, 757, 88, 990, 224, 526,
	}
	QuickSort(slice, 0, len(slice) - 1)
	fmt.Printf("%v", slice)
}

func QuickSort(slice []int, low int, high int) {
	if low > high {
		return
	}
	
	// Partion the slice around pivot value (in this case the last value of a (sub)slice)
	pivotIdx := Partition(slice, low, high)
	QuickSort(slice, low, pivotIdx - 1)
	QuickSort(slice, pivotIdx + 1, high)
}

func Partition(partionedSlice []int, low int, high int) (int) {
	pivot := partionedSlice[high]
	smallerPosIdx := low

	for x := low; x <= high; x++ {
		if partionedSlice[x] <= pivot {
			// Swap elements
			partionedSlice[x], partionedSlice[smallerPosIdx] = partionedSlice[smallerPosIdx], partionedSlice[x]
			smallerPosIdx += 1
		}
	}

	return smallerPosIdx - 1
}
