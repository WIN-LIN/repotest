import numpy as np
import timeit

#random array
size = 2**10
array = np.random.randint(1,1000,size)

#Time start
start = timeit.default_timer()

#sorting
# Python program for implementation of MergeSort
        MergeSort(array,size);

# Driver Code
if __name__ == '__main__':
	arr = [12, 11, 13, 5, 6, 7]
	print("Given array is", end="\n")
	printList(arr)
	mergeSort(arr)
	print("Sorted array is: ", end="\n")
	printList(arr)

# This code is contributed by Mayank Khanna




#Time end
end = timeit.default_timer()
print("Time measured:"+ str(end-start))
