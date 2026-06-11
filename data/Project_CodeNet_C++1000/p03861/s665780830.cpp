#include <bits/stdc++.h> 
using namespace std; 
  

long long countDivisibles(long long A, long long B, long long M) 
{ 
    if (A % M == 0) 
        return (B / M) - (A / M) + 1; 
  
    return (B / M) - (A / M); 
} 
  
int main() 
{ 
    long long a,b,m;
  	cin >> a >> b >> m;
   
    cout << countDivisibles(a, b, m) << endl; 
  
    return 0; 
} 
