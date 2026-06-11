//in the name of ALLAH
#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int main()
{
    ll n,k,x,y;
    cin>>n>>k>>x>>y;
    ll a=n-k;
    if(k>n){
        k=n;
        a=0;
    }
    cout<<x*k+a*y<<endl;

}

