import random

MAX_SIZE = 20
MIN_SIZE = 10
MAX_INT = 100

swaps = 0
comparisons = 0

size = random.randint(MIN_SIZE, MAX_SIZE + 1)

arrayList = []

for i in range(0, size):
  arrayList.append(random.randint(0, MAX_INT + 1))

print "LIST BEFORE SORTING: ", arrayList, "\n"

for i in range(0, size - 1):
  min_index = i;
  for j in range(i, size):
    comparisons += 1
    if(arrayList[j] < arrayList[min_index]):
      min_index = j
        
  temp = arrayList[i]
  arrayList[i] = arrayList[min_index]
  arrayList[min_index] = temp
  swaps += 1

print "LIST AFTER SORTING: ", arrayList
print "SWAPS: ", swaps
print "COMPARISONS: ", comparisons
