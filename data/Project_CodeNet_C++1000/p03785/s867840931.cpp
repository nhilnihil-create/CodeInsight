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
vector<int>t;
int n,c,k;
bool good(int num)
{
    int cnt=1;
    int last=t[0];
    int numofPass=1;
    for(int i=1;i<n;i++)
    {
        if(numofPass==c)
        {
            last=t[i];
            cnt++;
            numofPass=1;
        }
        else if(t[i]<=last+k)
        {
            numofPass++;
        }
        else{
            cnt++;
            last=t[i];
            numofPass=1;
        }
    }
    cout<<cnt<<endl;
    return true;
}
int32_t main() {
    nitin;
    cin>>n>>c>>k;
    for(int i=0;i<n;i++)
    {
        int a;
        cin>>a;
        t.push_back(a);
    }
    sort(t.begin(),t.end());
    good(0);
    return 0;
}
