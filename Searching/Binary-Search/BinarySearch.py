#For binary search the values have to be sorted
#Time complexity O(log n)

index = -1                              #initializing index variable with one
def bsearch(lst,n):
    l = 0
    u = len(lst)-1
    while(l<=u):
        mid = (l+u)//2
        if lst[mid] == n:
            globals()['index'] = mid
            return True                 #returns True if mid value is equal to element of search
        else:
            if lst[mid]<n:
                l = mid+1
            else:
                u = mid - 1

lst = [2,6,7,10,154,298]
n = 154

if bsearch(lst,n):
    print("Element found at position",index+1)
else:
    print("Element not found")

