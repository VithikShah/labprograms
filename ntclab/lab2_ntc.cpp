#include <bits/stdc++.h> 
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
  
string lucasTest(int n) 
{ 
   
    if (n == 1) 
        return "neither prime nor composite"; 
    if (n == 2) 
        return "prime"; 
    if (n % 2 == 0) 
        return "composite1"; 
          
          
  
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
            return "composite"; 
  
       
        bool flag = true; 
        for (int k = 0; k < factors.size(); k++) { 
            
            if (power(a, (n - 1) / factors[k], n) == 1) { 
                flag = false; 
                break; 
            } 
        } 
  
        
        if (flag) 
            return "prime"; 
    } 
    return "probably composite"; 
} 
  
int main() 

{ 
    int a;
    cout<<"enter the number"<<endl;;
    cin>> a;
    cout << a << " is " << lucasTest(a) << endl; 
    return 0; 
} 