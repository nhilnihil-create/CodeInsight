#include <bits/stdc++.h> 
using namespace std; 
typedef long long int ll;
typedef unsigned long long int ull;
const long long int m=pow(10,9)+7;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll n,a,b;
    cin>>n>>a>>b;
    if(a>b)
        cout<<"0"<<endl;
    else if(a==b&&n==1)
        cout<<"1"<<endl;
    else if(a!=b&&n==1)
        cout<<"0"<<endl;
    else
        cout<<(n - 2)*(b - a)+1<<endl;
    return 0;
}