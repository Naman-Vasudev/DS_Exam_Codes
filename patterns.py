def binary_search(arr1,target1):
    s=0
    e=len(arr1)-1
    while s<=e:
        mid=((2*s)+e)//3

        if arr1[mid]==target1:
            return mid
        elif arr1[mid]<target1:
            s=mid+1
        elif arr1[mid]>target1:
            e=mid-1
    return -1

arr1=[1,2,3,5,23,28,43,100]
target1=23
soln=binary_search(arr1,target1)

if soln==-1:
    print(f"Element {target1} not found")
else:
    print(f"Element {target1} found at index {soln}")