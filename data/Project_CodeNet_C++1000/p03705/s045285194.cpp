#include <bits/stdc++.h>
using namespace std;
 typedef long long ll;
 
int main() {
ll n,a,b;
cin>>n>>a>>b;
ll mi = a*(n-1)+b;
ll ma = b*(n-1)+a;
ll z=0;
cout<<max(ma-mi+1,z)<<endl;
}