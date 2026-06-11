#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{

 ll n ,x;
 cin >> n >> x;
 ll ara[n+10];
 for(ll i=0; i<n; i++)
 {
     cin >> ara[i];
 }
 ll sum = 0;
 for(int i=1; i<n; i++)
 {
     if(ara[i]+ara[i-1]>x)
     {
        ll todel = (ara[i] + ara[i-1])-x;
        sum += todel;
         if(ara[i]>=todel)
            {
                //sum += ara[i] - todel;
                ara[i] -= todel;

            }
         else
         {
             //s//um += ara[i];
             //ara[i] = 0 ;
             //sum += ara[i-1] - (todel - ara[i]);

             ara[i-1] = ara[i-1] - (todel - ara[i]);
             ara[i] = 0;
         }

     }

 }
 cout << sum << endl;



  }
