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
    int n;
    cin>>n;
    vector<int>v(n);
    for(auto &c:v) cin>>c;
    if(n==1 || n==2)
        cout<<1<<endl;
    else{
        int i=1;
        while(v[i]==v[i-1] && i<n)
            i++;
        int inc=false;
        if(v[i]>v[i-1])
            inc=true;
        int cnt=1;
        for(int j=i;j<n;)
        {
            if(v[j]==v[j-1] || (inc && v[j]>v[j-1]) || (!inc && v[j]<v[j-1]))
                j++;
            else
            {
                cnt++;
                if(j==n-1)
                {
                    break;
                }
                else{
                    j+=1    ;
                    while(v[j]==v[j-1] && j<n)
                        j++;
                    inc = j < n && v[j] - v[j - 1] > 0;

                }
            }
        }
        cout<<cnt<<endl;
    }
    return 0;
}