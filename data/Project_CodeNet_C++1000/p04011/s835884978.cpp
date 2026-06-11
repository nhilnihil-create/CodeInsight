#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
    int n,k,x,y;
    cin>>n>>k>>x>>y;

    cout<<min(k,n)*x+(n-min(k,n))*y<<"\n";
}
