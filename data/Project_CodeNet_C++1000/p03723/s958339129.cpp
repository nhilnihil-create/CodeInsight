#include <bits/stdc++.h> 
using namespace std; 
typedef long long int ll;
typedef long double ld;
typedef unsigned long long int ull;
const long long int m=pow(10,9)+7;

int main() 
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    ll a,b,c,cnt=0;
    cin>>a>>b>>c;
    while(1)
    {
        if(a%2!=0||b%2!=0||c%2!=0)
            {cout<<cnt<<endl;return 0;}
        if(a==b&&b==c)
            {cout<<"-1"<<endl;return 0;}
        ll t1,t2,t3;
        t1=a/2;
        t2=b/2;
        t3=c/2;
        a+=t2+t3;
        b+=t1+t3;
        c+=t1+t2;
        cnt++;
    }
    return 0;
}