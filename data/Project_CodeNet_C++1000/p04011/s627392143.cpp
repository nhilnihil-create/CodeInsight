/// @author MUSTAFA MOGHAZY
#include<bits/stdc++.h>
using namespace std;
#define ll long long
int main()
{
 int n, k, x, y;
 cin>>n>>k>>x>>y;
 ll sum = 0;
 if(n>=k){
 sum += k*x;
 sum += (n-k)*y;
 cout<<sum;
 }
 else
    cout<<n*x;
}
