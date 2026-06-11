#include<bits/stdc++.h>
using namespace std;
#define ll long long

int main()
{
 int mn = INT_MAX , mx = INT_MIN;
 int n;
 cin >> n;
 int ara[n+10];

 for(int i=0; i<n; i++)
 {
     cin >> ara[i];
     mn = min(mn,ara[i]);
     mx = max(mx,ara[i]);

 }
 int ans = INT_MAX;

 for(int i=mn; i<=mx; i++)
 {
     int tmp = 0;
     for(int j=0; j<n; j++)
     {
         tmp += (ara[j]-i)*(ara[j]-i);
     }

     ans = min(ans,tmp);

 }

 cout << ans << endl;




 }
