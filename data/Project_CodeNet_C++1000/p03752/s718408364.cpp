#include <bits/stdc++.h>

using namespace std;
typedef long long int ll;

int main()
{
   int n,k;
   cin >> n >> k;
   vector<ll>A(n),a(n);
   for(int i = 0; i < n; i++) cin >> A[i];
   ll cost = 1e11;
   for(int bit = 0; bit < (1<<n);bit++)
   {
       a = A;
       ll sum = 0;
       for(int i = 1; i < n; i++)
       {
           if(bit & (1<<i))
           {
               ll high = 0;
               for(int j = 0; j < i; j++)
               {
                   high = max(high,a[j]);
               }
               if(high >= a[i])
               {
                   sum += high - a[i] + 1;
                   a[i] = high + 1;
               }
           }
       }
       int see = 1;
       ll high = a[0];
       for(int i = 1; i < n; i++)
       {
           if(high < a[i])
           {
               see++;
               high = a[i];
           }
       }
       if(see >= k) 
       {
           cost = min(cost,sum);
       }
   }
   cout << cost << endl;
}
