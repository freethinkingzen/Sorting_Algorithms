
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

print "LIST BEFORE SORTING: ", arrayList

for i in range(0, size-1):  #Passes through array
  flag = 0
  for j in range(0, size-i-1):  #Adjacent comparisons
    comparisons += 1
    if(arrayList[j] > arrayList[j+1]):
      temp = arrayList[j]
      arrayList[j] = arrayList[j+1]
      arrayList[j+1] = temp
      swaps += 1

  if(flag == 0):
    i = size-1


print "LIST AFTER SORTING: ", arrayList
print "SWAPS: ", swaps
print "COMPARISONS: ", comparisons

