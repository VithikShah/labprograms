import random
def power(r, s, t): 
	res = 1; 
	r = r % t; 
	while (s > 0): 
		if (s & 1): 
			res = (res * r) % t; 
		s = s>>1;
		r = (r * r) % t; 
	return res;  
n=int(input("Enter the number\n"))
if(n<1):
	print("Invalid")
	exit()
if(n==1):
	print("Neither prime nor composite")
	exit()
if(n<4):
	print("Prime")
	exit()
if(n%2==0):
	print("Number is even")
	exit()
x=n-1
k=0
y=x
while (y%2==0):
	y//=2
	k+=1
m=y
a=random.randint(2,x)
b=power(a,m,n)
if((b==1) or (b==(n-1))):
	print("Prime")
	exit()
else:
	while(m!=n-1):
		m*=2
		b=power(b,2,n)
		if(b==1):
			print("Composite")
			exit()
		if(b==(n-1)):
			print("Prime")
			exit()
print("Composite")