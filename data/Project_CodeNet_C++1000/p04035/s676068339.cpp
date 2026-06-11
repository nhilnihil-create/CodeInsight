#include <bits/stdc++.h>

using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(),v.end()
#define _GLIBCXX_DEBUG
#define fi first
#define se second

using ll = long long;
using vi = vector<int>;
using vll = vector<ll>;
using vd = vector<double>;
using vvi = vector<vi>;
using vvll = vector<vll>;
using vvd = vector<vd>;
using vvvi = vector<vvi>;
using vvvll = vector<vvll>;
using vvvd = vector<vvd>;

const double pi=acos(-1);
const ll MOD=1e9+7;
const ll INF=(1LL<<60);

int main() {
    ll n,l;
    cin>>n>>l;
    ll a[n];
    rep(i,n)cin>>a[i];
    int index=-1;
    rep(i,n-1){
        if (a[i]+a[i+1]>=l){
            index=i;
            break;
        }
    }
    if (index==-1){
        cout<<"Impossible"<<endl;
        return 0;
    }
    cout<<"Possible"<<endl;
    for (int i=1;i<index+1;i++)cout<<i<<endl;
    for (int i=n-1;i>index+1;i--)cout<<i<<endl;
    cout<<index+1<<endl;

    return 0;
}