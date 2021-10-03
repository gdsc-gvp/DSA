#Time complexity O(n^2)

def ssort(lst):
    for i in range(len(lst)-1):
            min = i
            for j in range(i,len(lst)):     #finds minimum in each iterationn and swaps with ith value
                if lst[j] < lst[min]:
                    min = j

            temp = lst[i]
            lst[i] = lst[min]
            lst[min] = temp

lst = [5,32,425,23,10,4]
ssort(lst)

print(lst)