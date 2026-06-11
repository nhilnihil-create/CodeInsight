#include <bits/stdc++.h>
using namespace std;
#define REP(i,a) for(int i = 0; i < (a); i++)
#define ALL(a) (a).begin(),(a).end()
typedef long long ll;
typedef pair<int, int> P;
const int INF = 1e9;
const long long LINF = 1e18;
const long long MOD = 1e9 + 7;

signed main(){
    int n;
    cin >> n;
    int p[n];
    REP(i,n){
        cin >> p[i];
        p[i]--;
    }
    int a[n], b[n];
    REP(i,n){
        a[i] = 1 + 30000 * i;
        b[i] = 1 + 30000 * (n - 1 - i);
    }
    REP(i,n){
        b[p[i]] += i;
    }
    REP(i,n){
        cout << a[i] << " ";
    }
    cout << endl;
    REP(i,n){
        cout << b[i] << " ";
    }
    cout << endl;
    return 0;
}