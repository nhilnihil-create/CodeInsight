#include <algorithm>
#include <iostream>
#include <queue>
#include <cmath>
#include <string>
#include <iterator>
#include <map>
#include <set>
#include <iomanip>
#include <vector>
using namespace std;
using ll = long long;
using ld = long double;
using P = pair<int, int>;
using Graph = vector<vector<int>>;
int dx[] = {0, 1, 0, -1, 1, -1};
int dy[] = {1, 0, -1, 0, 1, 1};
#define INF 1000000000000
#define MAX 200001
#define MOD 1000000007
ll fac[MAX], finv[MAX], inv[MAX];
const int MX = 1000005;

int main(){
    int n,k;cin>>n>>k;
    ll ans=INF;
    vector<ll> a(n);
    for(int i=0;i<n;i++) cin>>a[i];
    for(int bit=0;bit<(1<<n);bit++){
        ll cost = 0;
        vector<ll> b(n);
        for(int i=0;i<n;i++) b[i] = a[i];
        for(int j=0;j<n;j++){
            if(bit>>j&1){
                ll max_height = 0;
                for(int k=0;k<j;k++){
                    max_height = max(max_height,b[k]);
                }
                if(max_height < b[j]) continue;
                else{
                    cost += max_height - b[j] + 1;
                    b[j] = max_height + 1;
                }
            }
        }
        int count = 1;
        ll max_height = b[0];
        for(int i=1;i<n;i++){
            if(max_height < b[i]){
                count++;
                max_height = b[i];
            }
        }
        if(count >= k) ans = min(ans, cost);
    }
    cout<<ans<<endl;
}