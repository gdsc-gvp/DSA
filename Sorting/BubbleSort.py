#Time Complexity O(n^2)

def bsort(lst):
    for i in range(len(lst)-1, 0, -1):
        for j in range(i):
            if lst[j]>lst[j+1]:     #if consecutive element is greater swap
                temp = lst[j]
                lst[j] = lst[j+1]
                lst[j+1] = temp

lst = [100,32,154,2,6,1]
bsort(lst)

print(lst)