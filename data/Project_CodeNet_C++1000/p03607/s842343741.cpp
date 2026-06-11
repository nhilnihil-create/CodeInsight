#include<bits/stdc++.h>
using namespace std;
const long long MOD = 1e9+7;
#define rep(i,n) for(int i=0;i<n;++i)
typedef long long int ll;
typedef unsigned long long ull;
template<class T> inline bool chmin(T& a, T b) {if (a > b) {a = b;return true;}return false;}
template<class T> inline bool chmax(T& a, T b) {if (a < b) {a = b;return true;}return false;}
typedef pair<ll,ll> P;


int main()
{
    int n;
    cin>>n;
    map<int,int>mp;
    rep(i,n)
    {
        int a;
        cin >> a;
        if(mp[a]==0)mp[a]=1;
        else if(mp[a]=1)mp.erase(a);
    }
    cout<<mp.size();
    return 0;
}