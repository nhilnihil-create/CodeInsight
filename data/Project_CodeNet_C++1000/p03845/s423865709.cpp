#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <stdio.h>
#include <vector>
#include <numeric>

using namespace std;
int main()
{
   long long int y,z,i,j,k,n,t[100],m,p,x;
   cin >> n;
   
   for(i=0;i<n;i++)
   {
       cin >> t[i];
   }
   cin >> m;
   while(m--)
   {
       cin >> p >> x;
       int s=0;
       for(i=0;i<n;i++)
       {
           if (i==p-1)
           {
               s = s+x;
           }
           
           else
           {
               s = s+t[i];
           }
       }
       
       cout << s << "\n";
   }
}
