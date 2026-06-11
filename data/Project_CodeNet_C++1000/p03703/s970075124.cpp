#include <bits/stdc++.h>
#define FOR(i,a,n) for(ll i=(ll)a;i<(ll)n;i++)
#define rep(i,n) FOR(i,0,n)
using namespace std;
typedef long long ll;

ll merge_cnt(vector<ll> &a) {
    int n = a.size();
    if (n <= 1) { return 0; }

    ll cnt = 0;
    vector<ll> b(a.begin(), a.begin()+n/2);
    vector<ll> c(a.begin()+n/2, a.end());

    cnt += merge_cnt(b);
    cnt += merge_cnt(c);

    int ai = 0, bi = 0, ci = 0;
    // merge の処理
    while (ai < n) {
        if ( bi < b.size() && (ci == c.size() || b[bi] <= c[ci]) ) {
            a[ai++] = b[bi++];
        } else {
            cnt += n / 2 - bi;
            a[ai++] = c[ci++];
        }
    }
    return cnt;
}

ll n,k,num;
vector<ll> a;
map<ll,int> mp;
int main(){
    cin>>n>>k;
    a.resize(n+1);
    mp[0]=1;
    FOR(i,1,n+1){
        cin>>a[i];
        a[i]-=k;
        a[i]*=-1;
        a[i]+=a[i-1];
        num+=mp[a[i]];
        mp[a[i]]++;
    }
    cout<<merge_cnt(a)+num<<endl;
}