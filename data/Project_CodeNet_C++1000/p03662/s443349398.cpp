#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
typedef long long ll;
#include <bits/stdc++.h>
using namespace std;
template<typename A, size_t N, typename T>
void Fill(A (&array)[N], const T &val){
    std::fill( (T*)array, (T*)(array+N), val );
}
ll n;
vector<vector<ll>> edge(1e5+10);
vector<ll> d1(1e5+10);
vector<ll> dn(1e5+10);
    
void saiki(vector<ll>& ref, ll distance, ll parent, ll now){
    ref[now] = distance;
    distance++;
    
    for (auto e : edge[now]) {
        if(e == parent)continue;
        saiki(ref,distance,now,e);
    }
}

int main() {
    // 黒陣営に属する数、白陣営に属する数、黒と白との間にある数
    // 距離から自動的に決まる
    
    std::cin >> n;
    for (int i = 0; i < n-1; i++) {
        ll a,b;
        std::cin >> a>>b;
        a--;b--;
        edge[a].push_back(b);
        edge[b].push_back(a);
    }
    
    saiki(d1,0,-1,0);
    saiki(dn,0,-1,n-1);
    
    ll result = 0;
    
    for (int i = 0; i < n; i++) {
        if(d1[i] <= dn[i]){
            result++;
        }
    }
    if( result*2>n ){
        std::cout << "Fennec" << std::endl;
    }else{
        std::cout << "Snuke" << std::endl;
    }
}
