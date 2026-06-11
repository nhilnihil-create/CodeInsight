#include <iostream>
#include <vector>
#include <string>
#include <cmath>
#include <algorithm>
#include <utility>
#include <queue>
#include <set>
#include <map>
#include <deque>
#include <iomanip>
#include <cstdio>
#include <stack>
#include <numeric>

using namespace std;
typedef  long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
#define  MP make_pair
#define  PB push_back
#define inf 1000000007
#define mod 1000000007
#define rep(i,n) for(int i=0;i<(int)(n);++i)


int main(){
    int n;
    cin >> n;
    vector<ll>a(n);
    rep(i,n)cin >> a[i];
    ll ans = 1;
    ll p = 0;
    rep(i,n){
        if(a[i]/2>=p){
            if(a[i]==2*p){
                p++;
                ans *=p;
                ans %= mod;
                p--;
            }else{
                p++;
            }
        }else{
            while(a[i]/2<p){
                ans *=p;
                ans %= mod;
                p--;
            }
            p++;
        }
        //cerr << ans << " " << p << endl;
    }
    while(p>=1){
        ans *=p;
        ans %= mod;
        p--;
    }
    cout << ans << endl;
    return 0;
}