#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define m 1000000007

int main()
{
 ll n;
 cin>>n;
 ll ans =1;
 for(int i=1;i<=n;i++)
 {
     ans = (ans*i)%m;
 }
 cout<<ans;
}