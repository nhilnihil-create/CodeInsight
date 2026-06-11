#include<bits/stdc++.h>
using namespace std;
#define  ft  ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);
#define  ll  long long
#define  pb  push_back
#define  F   first
#define  S   second
const int N=1e5+5;
string s;
int main()
{
    ft
    ll t,i,j,n,m,l=0,r,p,q,ss=0;
    cin>>n;
    m=(n/11)*2;
    if((n%11)>=7)
    {
        m+=2;
    }
    else if((n%11)>0)
    {
        m++;
    }
    cout<<m<<"\n";
    return 0;
}

