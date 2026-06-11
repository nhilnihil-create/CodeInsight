#include <bits/stdc++.h>
using namespace std;

int main()
{
   int k,s,z;
   cin >> k >> s;
   int count = 0;
   for(int i = 0; i<= k;i++){
      for(int j = 0;j<=k;j++){
         z = s-i-j;
         if(z <= k && z >=0)count++;         
      }
   }
   cout << count << endl;

   return 0;
}
