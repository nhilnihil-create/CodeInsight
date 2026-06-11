#include <bits/stdc++.h>
using namespace std;
int a[100003];
int main()
{ 
    int n;  
   cin >> n;    
   while (n--) 
  {        
      int x;       
      cin >> x;        
      a[x]++;
      a[x + 1]++;       
      a[x+ 2]++;    
  }   
     cout << *max_element(a + 2, a + 100000) << endl;  
  return 0;
}