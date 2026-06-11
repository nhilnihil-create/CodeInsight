#include <iostream>
#include <fstream>
#include <cstdio>
#include <cmath>
#include <vector>
#include <cstring>
#include <string>
#include <set>
#include <map>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;
 
#define REP(i,n) for(int i=0; i<n; ++i)
#define FOR(i,a,b) for(int i=a; i<=b; ++i)
#define FORR(i,a,b) for (int i=a; i>=b; --i)
#define pi M_PI
 
typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector<VI> VVI;
typedef pair<int,int> P;
typedef pair<ll,ll> PL;

const int N = 100001;

int main() {
    int n, m;
    cin >> n >> m;
    VI x(n);
    REP(i,n) scanf("%d", &x[i]);
    VI p(N), a(m), b(m);
    REP(i,n) p[x[i]]++;
    REP(i,N){
        a[i%m] += p[i];
        b[i%m] += p[i]/2;
    }

    int ans = 0;
    REP(i,m/2+1){
        int j = (m-i) % m;
        if (i == j){
            ans += a[i]/2;
        }else{
            int y = min(a[i], a[j]);
            ans += y;
            if (a[i] > a[j]) {
                ans += min((a[i]-y)/2, b[i]);
            }else{
                ans += min((a[j]-y)/2, b[j]);
            }
        }
    }
    cout << ans << endl;

    return 0;
}