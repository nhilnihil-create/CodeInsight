#include <bits/stdc++.h>
using namespace std;;
#define ll long long
#define REP(i, n) for(int i = 0;i < n;i++)
#define REPR(i, n) for(int i = n;i >= 0;i--)
#define FOR(i, m, n) for(int i = m;i < n;i++)
#define FORR(i, m, n) for(int i = m;i >= n;i--)
#define INF 1<<30
#define LINF 1LL<<62
typedef pair<int, int> P;
typedef pair<ll, ll> LP;
typedef pair<int, P> PP;
typedef pair<ll, LP> LPP;
int main(){
    int n; cin >> n;
    int p[n];
    REP(i,n){
        cin >> p[i];p[i]--;
    }
    int ans=0;
    REP(i,n){
        if(p[i] == i){
            swap(p[i], p[i+1]);
            ans++;
        }
    }
    cout << ans << endl;

}