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
    cin >> n;
    map<int,int>mp;
    vector<int> twe;
    rep(i,n)
    {
        int a;
        cin >> a;
        mp[a]++;
        if(mp[a]%2==0) twe.push_back(a);
    }
    sort(twe.begin(),twe.end());
    int l=twe.size();
    if(l<2)cout<<0<<endl;
    else cout<<(ll)twe[l-1]*twe[l-2]<<endl;
 
    return 0;
}