#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include<bitset>
#include<set>
#include<map>
#include<stack>
#include<queue>
#include<deque>
#include<list>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<functional>
#include<cstdio>
#include<cstdlib>
#include<unordered_map>
#include<unordered_set>
using namespace std;

#define repr(i, a, b) for (int i = (int)(a); i < (int)(b); i++)
#define rep(i, n) repr(i, 0, n)
#define INF 2e9
#define MOD 1000000007
//#define MOD 998244353
#define LINF (long long)4e18
#define jck 3.141592
#define PI acos(-1.0);

const double EPS = 1e-10;

using ll = long long;
using Pi = pair<int,int>;
using Pl = pair<ll,ll>;



int main(){
    int N,x; cin >> N >> x;
    if(x == 1 || x == 2*N-1){
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    vector<int> ans(2*N-1);
    vector<bool> ok(2*N-1,false);
    if(x == 2){
        int d = (2*N-1)/2;
        ans[d-1] = x+1;
        ans[d] = x;
        ans[d+1] = x-1;
        ans[d+2] = x+2;
        ok[d-1] = ok[d] = ok[d+1] = ok[d+2] = true;
        int now = 5;
        rep(i,2*N-1){
            if(!ok[i]){
                ans[i] = now;
                ok[i] = true;
                now++;
            }
        } 
    }
    else{
        int d = (2*N-1)/2;
        ans[d-1] = x-1;
        ans[d] = x;
        ans[d+1] = x+1;
        ans[d+2] = x-2;
        ok[d-1] = ok[d] = ok[d+1] =ok[d+2] = true;
        int now = 1;
        rep(i,2*N-1){
            if(now == x-2) now += 4;
            if(!ok[i]){
                ans[i] = now;
                ok[i] = true;
                now++;
            }
        }
    }
    rep(i,2*N-1) cout << ans[i] << endl;
}

