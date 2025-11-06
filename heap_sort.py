import heapq
from os import name
class Heap: 
    def __init__ (self): 
        self.arr = []
    def heapify(self, n, i): 
        largest = i 
        left = 2 * i + 1 
        right = 2 * i + 2 
        if left < n and self.arr[left] > self.arr[largest]: 
            largest = left 
        if right < n and self.arr[right] > self.arr[largest]: 
            largest = right 
        if largest != i: 
            self.arr[i], self.arr[largest] = self.arr[largest], self.arr[i] 
            self.heapify(n, largest) # Recursively heapify affected subtree 
    # Build max-heap from the array 
    def build_max_heap(self):
        n = len(self.arr) 
        for i in range(n // 2 - 1, -1, -1): 
            self.heapify(n, i) 
    # Perform Heap Sort 
    def heapsort(self): 
        n = len(self.arr) 
        self.build_max_heap() 
        for i in range(n - 1, 0, -1): 
            self.arr[0], self.arr[i] = self.arr[i], self.arr[0] 
            self.heapify(i, 0) 
    # Display array 
    def display(self): 
        print(' '.join(map(str, self.arr))) 

heap = Heap() 
# Input array from user 
n = int(input("Enter number of elements: ")) 
print("Enter elements:") 
for _ in range(n): 
    element = int(input()) 
    heap.arr.append(element) 
print("Array before sorting:") 
heap.display() 
heap.heapsort() 
print("Array after sorting:") 
heap.display()