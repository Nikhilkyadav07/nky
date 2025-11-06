# Function to perform Merge Sort on the list of delivery times
def merge_sort(orders):
    if len(orders) > 1:
        mid = len(orders) // 2       # Find the middle point
        left_half = orders[:mid]     # Divide the list into two halves
        right_half = orders[mid:]

        # Recursively sort both halves
        merge_sort(left_half)
        merge_sort(right_half)

        # Merge the sorted halves
        i = j = k = 0

        while i < len(left_half) and j < len(right_half):
            if left_half[i] <= right_half[j]:
                orders[k] = left_half[i]
                i += 1
            else:
                orders[k] = right_half[j]
                j += 1
            k += 1

        # Copy remaining elements of left_half (if any)
        while i < len(left_half):
            orders[k] = left_half[i]
            i += 1
            k += 1

        # Copy remaining elements of right_half (if any)
        while j < len(right_half):
            orders[k] = right_half[j]
            j += 1
            k += 1


# --- Main Program ---
n = int(input("Enter number of orders: "))
orders = []

for i in range(n):
    time = int(input(f"Enter estimated delivery time (in minutes) for order {i+1}: "))
    orders.append(time)

print("\nOriginal delivery times:", orders)

merge_sort(orders)

print("Sorted delivery times (quicker first):", orders)
