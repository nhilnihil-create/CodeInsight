#include <bits/stdc++.h>
using namespace std;
int main()
{
 long long n,i,j,s=0,c=0,k,w,a,b;
 cin>>w>>a>>b;
 i=max(a,b);
 j=min(a,b);
 if((i-j-w)<=0) cout<<"0"<<endl;
 else cout<<i-j-w<<endl;
return 0;
}
