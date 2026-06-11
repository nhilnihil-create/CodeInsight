#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <climits>
#include <cmath>
#include <complex>
#include <cstring>
#include <deque>
#include <functional>
#include <iostream>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <cstdint>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef pair<int,int> pii;
#define MP make_pair
#define PB push_back
#define inf 1000000007
#define mod 1000000007
#define rep(i,n) for(int i = 0; i < (int)(n); ++i)
#define all(x) (x).begin(),(x).end()

template<class T> inline bool chmax(T &a, T b){
    if(a<b){
        a = b;
        return true;
    }
    return false;
}

template<class T> inline bool chmin(T &a, T b){
    if(a>b){
        a = b;
        return true;
    }
    return false;
}

int main(){
    int n;
    cin >> n;
    vector<pair<ll,ll> >a;
    set<ll>st;
    st.insert(-1);
    st.insert(n);
    rep(i,n){
        ll s;
        cin >> s;
        a.push_back(MP(s,i));
    }
    sort(a.begin(),a.end());
    ll sm = 0;
    rep(i,n){
        ll c = a[i].first;
        ll p = a[i].second;
        auto  itr = st.lower_bound(p);
        itr--;
        ll low = *itr;
        auto  itr2 = st.upper_bound(p);
        ll high = *itr2;
        sm += c * (high-p) * (p-low);
        st.insert(p);
    }
    cout << sm << endl;
    return 0;
}