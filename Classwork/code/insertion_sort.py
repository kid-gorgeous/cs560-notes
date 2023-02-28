# Insertion Sort 

arr = [5, 2, 4, 6, 1, 3]


def insertion_sort(arr):
    
    n  = len(arr)
    for i in range(1,n):
        key = arr[i]
        j = i-1
        while j >= 0 and key < arr[j]:
            arr[j+1] = arr[j]
            j -= 1
        arr[j+1] = key
    return arr


insertion_sort(arr)