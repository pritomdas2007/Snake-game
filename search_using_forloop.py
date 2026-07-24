lst = [1,4,9,16,25,36,49,64,81,100]
ind = 0
n= int(input("Enter the number to be searched:"))
for i in lst:
    ind+=1
    if n==i:
        print("Number is found",ind)
        break
    else:
        print("not found")
