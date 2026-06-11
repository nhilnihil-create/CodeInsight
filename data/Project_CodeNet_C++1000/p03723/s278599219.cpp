#include <bits/stdc++.h>

#define int long long
#define counter(m)     for(int i=0;i<m;i++)
#define gcd            __gcd
#define endl           "\n"
#define pb             emplace_back
#define setbits(x)     __builtin_popcountll(x)
#define zrobits(x)     __builtin_ctzll(x)
#define mod            1000000007
#define mod2           998244353
#define maxe           *max_element
#define mine           *min_element
#define inf            1e18
#define deci(x, y)      fixed<<setprecision(y)<<x
#define w(t)           int t; cin>>t; while(t--)
#define nitin          ios_base::sync_with_stdio(false); cin.tie(NULL)
#define PI             3.141592653589793238
using namespace std;

int32_t main() {
    nitin;
    int a,b,c;
    cin>>a>>b>>c;
    int cnt=0;
    if(a%2!=0 || b%2!=0 || c%2!=0)
    {
        cout<<0<<endl;
        exit(0);
    }
    if(a==b && b==c && c==a)
    {
        cout<<-1<<endl;
        exit(0);
    }
    while(a%2==0 && b%2==0 && c%2==0)
    {
        if(a==b && b==c && c==a)
        {
            cout<<-1<<endl;
            exit(0);
        }
        int A,B,C;
        A=(c+b)/2;
        B=(a+c)/2;
        C=(b+a)/2;
        a=A;
        b=B;
        c=C;
        cnt++;

    }
    cout<<cnt<<endl;
    return 0;
}