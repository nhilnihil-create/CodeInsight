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
    string s;
    cin>>s;
    vector<int>v(26,0);
    for(auto c:s)
        v[c-'a']++;
    int cnt=0;
    for(auto c:v)
        if(c!=0)
            cnt++;
        if(cnt==1)
        {
            cout<<0<<endl;
            return 0;
        }
    int n=s.length();
    int ans=n-1;
    for(int i=n-1;i>=1;i--)
    {
        char op1=s[i];
        char op2=s[i-1];
        //op1
        vector<int>a;
        a.push_back(-1);
        for(int j=0;j<=i;j++)
        {
            if(s[j]==op1)
                a.push_back(j);
        }
        vector<int>b;
        b.push_back(-1);
        for(int j=0;j<i;j++)
        {
            if(s[j]==op2)
            {
                b.push_back(j);
            }
        }
        int temp=INT_MIN;
        for(int j=1;j<a.size();j++)
        {
            temp=max(temp,a[j]-a[j-1]-1);
        }
        int ntemp=INT_MIN;
        for(int j=1;j<b.size();j++)
        {
            ntemp=max(ntemp,b[j]-b[j-1]-1);
        }
        ans=min(ans,max(min(ntemp,temp),n-i));
    }
    cout<<ans<<endl;
    return 0;
}