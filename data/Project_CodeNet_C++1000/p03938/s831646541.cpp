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
    int N; cin >> N;
    vector<int> p(N);
    rep(i,N) cin >> p[i],p[i]--;
    vector<int> a(N),b(N);
    a[0] = 1;
    rep(i,N-1){
        a[i+1] = a[i]+20000;
    }
    b[N-1] = 1;
    for(int i = N-1; i >= 1; i--){
        b[i-1] = b[i]+20000;
    }
    int now = 0;
    rep(i,N){
        b[p[i]] += now;
        now++;
    }
    rep(i,N) cout << a[i] << " ";
    cout << endl;
    rep(i,N) cout << b[i] << " ";
    cout << endl;
}

