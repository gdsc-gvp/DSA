def linearsearch(a, s):
    for i in range(len(a)):
        if a[i] == s:
            return i+1
    return -1


n = int(input("Enter number of elements : "))
a = list(map(int, input("\nEnter the numbers : ").strip().split()))[:n]
s = int(input("Enter the number to be found : "))
if linearsearch(a, s) == -1:
    print("Element not found")
else:
    print("element found at index "+str(linearsearch(a, s)))
