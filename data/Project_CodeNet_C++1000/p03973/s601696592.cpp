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

using namespace std;
typedef  long long ll;
typedef pair<int,int> PII;
typedef vector<int> VI;
typedef vector<VI> VVI;
#define  MP make_pair
#define  PB push_back
#define inf  1000000007
#define rep(i,n) for(int i=0;i<(int)(n);++i)

int main(){
    int n;
    cin >> n;
    vector<ll> v(n);
    rep(i,n)cin >> v[i];
    ll x = 1;
    ll ans = 0;
    for(int i=0;i<n;i++){
        ll tmp = (v[i]-1)/x;
        ans += tmp;
        if(v[i]==x){
            x++;
        }
        if(i==0){
            x = 2;
        }
    }
    cout << ans << endl;
    return 0;
}