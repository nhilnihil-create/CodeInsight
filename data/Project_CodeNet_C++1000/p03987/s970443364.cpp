#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<bitset>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<deque>
#include<list>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<functional>
using namespace std;

#define repr(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) repr(i, 0, n)
#define INF 2e9
#define MOD 1000000007
//#define MOD 998244353
#define LINF (long long)4e18
#define jck 3.141592

using ll = long long;
using Pi = pair<int,int>;
using Pl = pair<ll,ll>;


int main(){
    int N; cin >> N;
    vector<Pi> a(N);
    rep(i,N){
        cin >> a[i].first;
        a[i].second = i;
    }
    sort(a.rbegin(),a.rend());
    set<int> st;
    rep(i,N) st.insert(i);
    st.insert(-1);
    st.insert(N);
    ll ans = 0;
    rep(i,N){
        auto p = st.upper_bound(a[i].second);
        ll n1 = *p-a[i].second;
        p--;
        p--;
        ll n2 = a[i].second-*p;
        ans += n1*n2*a[i].first;
        st.erase(a[i].second);
    }
    cout << ans << endl;
}
    

