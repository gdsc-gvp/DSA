#Time complexity O(n)

index = -1              #Giving a value -1 to index variable
def lsearch(lst, n):    #Takes list and the value to be searched as arguments
    for i in range (len(lst)):
        if (lst[i]==n):
            globals()['index'] = i      #since index variable is out of scope using gloabals
            return True
    return False                        #Returns falls if required value is not encountered in list


lst = [79,121,25,16,3]
n = 25

if lsearch(lst,n):                      #if Function returns true
    print("Element found at position",(index+1))

else:                                   #if function returns false
    print("Elemnt not found")
