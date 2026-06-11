#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <utility>
#include <vector>
#define p(s) cout<<(s)<<endl
#define REP(i,n,N) for(int i=n;i<N;i++)
#define RREP(i,n,N) for(int i=N-1;i>=n;i--)
#define CK(n,a,b) ((a)<=(n)&&(n)<(b))
#define F first
#define S second
typedef long long ll;
using namespace std;
const int inf = 1e9+7;

map<ll, int> m;
int N;
ll H, W;
ll cnt[11];
int main() {
    cin>>H>>W>>N;
    REP(k,0,N){
        ll a,b;
        cin>>a>>b;
        REP(i,-1,2){
            REP(j,-1,2){
                if(CK(a+i,2,H)&&CK(b+j,2,W))m[W*(a+i)+(b+j)]++;
            }
        }
    }
    cnt[0]=(H-2)*(W-2);
    for(auto mp : m){
        cnt[mp.second]++;
        cnt[0]--;
    }
    REP(i,0,10){
        p(cnt[i]);
    }
    return 0;
}