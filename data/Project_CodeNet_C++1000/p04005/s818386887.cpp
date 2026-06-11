#include<iostream>
#include<algorithm>
using namespace std;
#define rep(i,n) for(int i=0;i<(n);i++)
int main()
{
    long long a,b,c;
    cin>>a>>b>>c;
    if(a%2==0||b%2==0||c%2==0) cout<<"0";
    else cout<<min(a*b,min(b*c,c*a));
}