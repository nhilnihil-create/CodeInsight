#include <bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i, n) for (int i = 0; i < (n); ++i)
#define rrep(i, n) for (int i = 1; i < (n+1); ++i)
using namespace std;
using ll = long long;
const int INF = +100100100;
typedef pair<ll,ll> P;
const ll MO = 1000000007;

int main(){
    int n;
    cin >> n;
    vector<ll> a(n);
    rep(i,n)cin>>a[i];
    sort(a.begin(),a.end());
    stack<P> st;
    ll pre = a[0];
    rrep(i,n-1){
        if(pre==a[i]){
            st.emplace(pre,a[i]);
            pre=0;
        }
        else pre = a[i];
    }
    ll x,y;
    if(st.size()>=2){
        x = st.top().first;st.pop();
        y = st.top().first;st.pop();        
    }else {
        x = 0; y = 0;
    }

    cout << x * y << endl;
    return 0;

}