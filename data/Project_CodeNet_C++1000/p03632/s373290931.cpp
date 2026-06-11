#include <bits/stdc++.h> 
using namespace std; 

int main() {
     int a,b,c,d;
     cin >> a >> b >> c >> d;
     
     int start,end,ans;
     
     start = max(a,c);
     end = min(b,d);
     
     ans = end - start;

     if(ans > 0)
          cout  << ans;
     else
          cout << 0;
     
    return 0; 
} 