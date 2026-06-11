#include <algorithm>
#include <bitset>
#include <complex>
#include <deque>
#include <exception>
#include <fstream>
#include <functional>
#include <iomanip>
#include <ios>
#include <iosfwd>
#include <iostream>
#include <istream>
#include <iterator>
#include <limits>
#include <list>
#include <locale>
#include <map>
#include <memory>
#include <new>
#include <numeric>
#include <ostream>
#include <queue>
#include <set>
#include <sstream>
#include <stack>
#include <stdexcept>
#include <streambuf>
#include <string>
#include <typeinfo>
#include <utility>
#include <valarray>
#include <vector>
#if __cplusplus >= 201103L
#include <array>
#include <atomic>
#include <chrono>
#include <condition_variable>
#include <forward_list>
#include <future>
#include <initializer_list>
#include <mutex>
#include <random>
#include <ratio>
#include <regex>
#include <scoped_allocator>
#include <system_error>
#include <thread>
#include <tuple>
#include <typeindex>
#include <type_traits>
#include <unordered_map>
#include <unordered_set>
#endif

long long max(long long x, long long y){return (x > y ? x : y);}
long long min(long long x, long long y){return (x < y ? x : y);}

#define ll long long
#define pb push_back
#define ld long double
#define mp make_pair
#define F first
#define S second
#define pii pair<ll,ll> 

using namespace :: std;

const ll maxn=1e5+5000;
const ll inf=1e17+800;
const ll mod=1e9+7;

ll dp[maxn][5];

ll a[maxn];
char c[maxn];
int main(){
    ios_base::sync_with_stdio(0);cin.tie(0);cout.tie(0);    

    ll n;
    cin>>n;
    c[1]='+';
    cin>>a[1];
    for(ll i=2;i<=n;i++){
        cin>>c[i]>>a[i];
    }
    dp[0][0]=0;
    for(ll i=1;i<5;i++){
        dp[0][i]=-inf;
    }
    ll v;
    for(ll i=1;i<=n;i++){
        for(ll j=0;j<5;j++){
            dp[i][j]=-inf;
            for(ll k=0;k<5;k++){
                // dp[i][j]
                if(c[i]=='-'){ 
                    ll x=j+k-1;
                    if(x%2==0){
                        v=-a[i];
                    }else{
                        v=a[i];
                    }
                    if(0<=x && x<5){
                        dp[i][j]=max(dp[i][j],dp[i-1][x]+v);
                    }
                }else{
                    ll x=j+k;
                    if(x%2==0){
                        v=a[i];
                    }else{
                        v=-a[i];
                    }
                    if(0<=x && x<5){
                        dp[i][j]=max(dp[i][j],dp[i-1][x]+v);
                    }
                }
            }
        }
    }
    cout<<dp[n][0];
}






























