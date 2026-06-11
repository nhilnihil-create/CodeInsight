#include <iostream>
#include <cstdio>
#include <vector>
#include <deque>
#include <algorithm>
#include <map>
 
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
#define REP(i, n) for(int i=0; i<n; i++)
const int MAX_N = 100100;
 
ll H,W,N;
ll ans[10];
map<pair<int, int>, int> m;
int main(){
    cin >> H >> W >> N;
    REP(i,N){
        ll a,b;
        cin >> a >> b;
        a--, b--;
        for(int k = a-2; k <= a; k++){
            for(int l = b-2; l <= b; l++){
                if(0 <= k && k+2 < H && 0 <= l && l+2 < W){
                    m[make_pair(k,l)]++;
                }
            }
        }
    }

    int sum = 0;
    for(auto&& x : m){
        //printf("x:%d\n", x.second);
        ans[x.second]++;
        sum++;
    }

    ans[0] = (H-2)*(W-2) - sum;
    for(int i = 0; i < 10; i++){
        printf("%lld\n", ans[i]);
    }
    return 0;
}
