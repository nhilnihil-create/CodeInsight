#include <bits/stdc++.h>
using namespace std;
char o;long long x,n,a,b,c;int main(){b=c=-1e18;cin>>n>>a;for(int i=1;i<n;++i){cin>>o>>x;if(o^'-')a+=x,c+=x,b=max(b-x,c);else c=b+x,a=b=max(a-x,c);}cout<<a;}