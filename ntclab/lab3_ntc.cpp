#include<bits/stdc++.h>
#include<iostream>
#include<fstream>
using std::ofstream;
#include<algorithm>
#include<cstdlib>
using namespace std;

void primeFactors(int n, vector<int>& factors) 
{ 
    
    if (n % 2 == 0) 
        factors.push_back(2); 
    while (n % 2 == 0) 
        n = n / 2; 
          
     
    for (int i = 3; i <= sqrt(n); i += 2) { 
        if (n % i == 0) 
            factors.push_back(i); 
        while (n % i == 0) 
            n = n / i; 
    } 
    if (n > 2) 
      factors.push_back(n); 
} 

int power(int n, int r, int q) 
{ 
    int total = n; 
    for (int i = 1; i < r; i++) 
        total = (total * n) % q; 
    return total; 
} 
  
bool lucasTest(int n) 
{ 
   
    if (n == 1) 
        return false; 
    if (n == 2) 
        return true; 
    if (n % 2 == 0) 
        return false; 
          
          
  
    vector<int> factors; 
    primeFactors(n - 1, factors); 
  
     
    int random[n - 3]; 
    for (int i = 0; i < n - 2; i++) 
        random[i] = i + 2; 
          
    
    shuffle(random, random + n - 3,  
               default_random_engine(time(0))); 
  
   
    for (int i = 0; i < n - 2; i++) { 
        int a = random[i];  
        if (power(a, n - 1, n) != 1)  
            return false; 
  
       
        bool flag = true; 
        for (int k = 0; k < factors.size(); k++) { 
            
            if (power(a, (n - 1) / factors[k], n) == 1) { 
                flag = false; 
                break; 
            } 
        } 
  
        
        if (flag) 
            return true; 
    } 
    return false; 
} 

int gcd(int r1,int r2){
	int q;
	int r;
	while(r2>0){
		q=r1/r2;;
		r=r1-q*r2;
		r1=r2;
		r2=r;
	}
	return r1;
}

int main(){
	ofstream outdata;
	outdata.open("file1.txt");
	int n,k;
	cin>>n>>k;
	outdata<<"N="<<n<<endl;
	outdata<<"K="<<k<<endl;
	if(n<0||k<0){
		cout<<"Not Found";
		outdata<<"Not Found";
	}
	int flag=0;
	for(int i=1;i<=n;i++){
		long long int d=n*k+i*i;
		long  double s=sqrt(d);
		if(s-floor(s)==0){
			cout<<"Found perfect square: "<<s<<endl;
			outdata<<"Found perfect square: "<<s<<endl;
			long long int a=s+i;
			long long int b=s-i;
			if(b<0){
				break;
			}
			cout<<"a="<<a<<endl;
			outdata<<"a="<<a<<endl;
			cout<<"b="<<b<<endl;
			outdata<<"b="<<b<<endl;
			long int a1=gcd(n,a);
			long int a2=gcd(n,b);
			cout<<"GCD of n and a: "<<a1<<endl;
			outdata<<"GCD of n and a: "<<a1<<endl;
			cout<<"GCD of n and b: "<<a2<<endl;
			outdata<<"GCD of n and b: "<<a2<<endl;
			if(lucasTest(a1)&&lucasTest(a2)){
				cout<<"Both are found to be prime"<<endl;
				outdata<<"Both are found to be prime"<<endl;
				flag=1;
				cout<<"Found"<<endl;
				outdata<<"Found"<<endl;
			}

			break;
		}
	}
	
	if(!flag){
		cout<<"Not Found"<<endl;
		outdata<<"Not Found"<<endl;
	}
}