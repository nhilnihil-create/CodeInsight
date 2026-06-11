/*
* Welcome to my code!
*---------------------------------------------*
* author : lynmisakura(twitter : @andoreiji11)
*/
#include <iostream>
#include <limits.h>
#include <algorithm>
#include <bitset>
#include <cctype>
#include <cmath>
#include <chrono>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <functional>
#include <iomanip>
#include <list>
#include <map>
#include <numeric>
#include <set>
#include <sstream>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>
#include <cassert>

using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define repn for(int i = 0;i < n;i++)
#define ain(a) for(auto& i : a)cin >> i;
#define all(x) (x).begin(),(x).end()
#define sz(x) (int)(x.size()) 
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define cont continue

using ll = long long;
using vi = vector<int>;
using vvi = vector<vi>;
using vl = vector<ll>;
using pi = pair<int,int>;
using vpi = vector<pi>;
using pl = pair<ll,ll>;
using vpl = vector<pl>;

template<class T> bool chmin(T& a,T b){if(a > b){a = b;return true;}else return false;}
template<class T> bool chmax(T& a,T b){if(a < b){a = b;return true;}else return false;}
template<class T> void print(std::vector<T> a){ int sz = a.size();
for(int i=0;i<a.size();i++)cout << a[i] << (i < sz-1 ? ' ' : '\n'); }
void ioboost(){cin.tie(0);ios::sync_with_stdio(false);cout<<fixed<<setprecision(20);}
///////////////////////////////////////////////////////////

int main(void){
    
    ll n,x;
    cin >> n >> x;
    vl a(n),b(n);
    for (size_t i = 0; i < n; i++)
    {
        cin >> a[i];
    }

    ll ans = 1e18;

   for (int k = 0; k < n; k++) {
       ll cur = 0;
       for (int i = 0; i < n; i++) {
           if (k == 0) { b[i] = a[i]; }
           else { chmin(b[i] , a[(i - k + n) % n]); }
           cur += b[i];
        }
        chmin(ans,cur + (ll)k * x);
   }

   cout << ans << '\n'; 
}