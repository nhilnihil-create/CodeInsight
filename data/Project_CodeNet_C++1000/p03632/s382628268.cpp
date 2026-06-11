#include <bits/stdc++.h> 
using namespace std;int main(){int a,b,c,d;cin>>a>>b>>c>>d;a=max(a,c);b=min(b,d);b-=a;cout<<(b<0?0:b);}