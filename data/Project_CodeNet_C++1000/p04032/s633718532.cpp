#include <iostream>
#include<cmath>
#include<vector>
#include<tuple>
#include <ctime>
#include<algorithm>
#include <initializer_list>
#include <cstring> 
#include <queue>

using namespace std;
 
#define tii tuple<int,int>
#define vi vector<int>
#define vii vector<vi>
#define ll long long
#define vl vector<ll>
#define vll vector<vl>
 
#define mymod 1000000007
#define sz 200002

ll power(ll a, ll b, ll p)
{
    if(a<2)
    return a;
    ll ans = 1;
    while(b)
    {
        if(b%2)
        {
            ans *= a;
            ans %= p;
        }
        b = b/2;
        a = (a*a)%p;
    }
    return ans;
}

ll mgcd(ll a, ll b)
{
    if(a==0)
        return b;
    return mgcd(b%a,a);
}

int main() {
    clock_t tstart = clock();
    ios_base::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);
    // Start
    string s;
    cin>>s;
    for(int i=0;i<s.length()-2;i++) {
        vector<char> v{s[i],s[i+1], s[i+2]};
        sort(v.begin(), v.end());
        if(v[0]==v[1] || v[1] == v[2]) {
            cout<<i+1<<" "<<i+3;
            return 0;
        }
    }
    for(int i=0;i<s.length()-1;i++) {
        if(s[i] == s[i+1]) {
            cout<<i+1<<" "<<i+2;
            return 0;
        }
    }
    cout<<"-1 -1";
    // cout<<"\n\nTotal Time Taken : "<<(double)(-tstart + clock())/CLOCKS_PER_SEC<<"sec\n\n";
    return 0;
}
 
