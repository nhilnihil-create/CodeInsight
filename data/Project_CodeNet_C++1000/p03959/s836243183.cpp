#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <cmath>
#include <complex>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <iterator>
#include <limits>
#include <list>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <ratio>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <utility>
#include <vector>
#include <climits>
#include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/trie_policy.hpp>
#define ll long long
#define ld long double
#define mp make_pair
#define pb push_back
#define in insert
#define vll vector<ll>
#define endl "\n"
#define pll pair<ll,ll>
#define f first
#define s second
#define int ll
#define sz(x) (ll)x.size()
#define all(x) (x.begin(),x.end())
using namespace std;
using namespace __gnu_pbds;
typedef tree<int,null_type,less<int>,rb_tree_tag,tree_order_statistics_node_update> os;
 
 
const ll INF = 1e18;
const ll N =(1e5+5);
const ll MOD = 1e9+7;
ll t[N];
ll a[N];
ll w[N];
ll w2[N];
ll sure[N];
ll sure2[N];
void solve(){
    ll n;
    cin >> n;
    for(int i =1;i<=n;i++){
        cin >> t[i];
    }
    for(int i =1;i<=n;i++){
        cin >> a[i];
    }
    if(a[1] != t[n]){
        cout << 0 << endl;
        return;
    }
    w[1] = 1;
    sure[1] = t[1];
    for(int i =2;i<=n;i++){
        sure[i]= -1;
        if(t[i] == t[i-1]) w[i] = t[i];
        else w[i] = 1,sure[i] = t[i];
    }
    w2[n] = 1;
    sure2[n]=a[n];
    for(int i = n-1;i>=1;i--){
        sure2[i] = -1;
        if(a[i] == a[i+1]) w2[i] = a[i];
        else w2[i] = 1,sure2[i] = a[i];
    }
    for(int i =1;i<=n;i++){
        if(sure[i] != -1){
            if(a[i] < sure[i]){
                cout << 0 << endl;
                return;
            }
        }

    }
    for(int i =n;i>=1;i--){
        if(sure2[i] != -1){
            if(t[i] < sure2[i]){
                cout << 0 << endl;
                return;
            }
        }
    }

    ll ans = 1;
    for(int i = 1;i<=n;i++){
        ans = (ans * min(w[i],w2[i]))%MOD;
    }
    cout << ans << endl;

}

signed main(){

    ios_base::sync_with_stdio(0);
    cin.tie(NULL);
    

 
     ll tt=1;   
    while(tt--){    
        solve();
    }    
}