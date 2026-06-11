#include <bits/stdc++.h>
#define rep(n) for(int I = 0; (I) < (n); ++(I) )
#define repeat(i, n) for( int i = 0; (i) < (n); ++(i) )
#define repeat_to(i, n) for( int i = 0; (i) <= (n); ++(i) )
#define repeat_from(i, m, n) for( int i = (m); (i) < (n); ++(i) )
#define repeat_from_to(i, m, n) for( int i = (m); (i) <= (n); ++(i) )
#define el cout<<endl
#define dump(x) cout<<" "<<#x<<"="<<x
#define vdump(v) for(size_t I=0; I<v.size(); ++I){cout<<" "<<#v<<"["<<I<<"]="<<v[I];} cout<<endl
using namespace std;
using lint = long long;
using ld = long double;

int main(void) {
    int n, m; cin >> n >> m;
    vector<lint> brightness(n); repeat(i, n) cin >> brightness[i];
    
    vector<lint> a(m+1, 0), b(m+1, 0), da(m+1, 0), db(m+1, 0), cost(m+1, 0);
    
    repeat(i, n-1) {
        lint s = brightness[i];
        lint t = brightness[i + 1];
        if (s < t) {
            da[s] += (-1);
            da[t] -= (-1);
            
            db[0] += (t - s);
            db[s] -= (t - s);
            db[s] += (t + 1);
            db[t] -= (t + 1);
            db[t] += (t - s);
        }
        else {
            da[0] += (-1);
            da[t] -= (-1);
            da[s] += (-1);
            
            db[0] += (t + 1);
            db[t] -= (t + 1);
            db[t] += (m + t - s);
            db[s] -= (m + t - s);
            db[s] += (m + t + 1);
        }
    }
    
    a[0] = da[0];
    b[0] = db[0];
    repeat_from(i, 1, m) {
        a[i] += a[i-1] + da[i];
        b[i] += b[i-1] + db[i];
    }
    
    cost[0] = numeric_limits<lint>::max();
    repeat_from_to(i, 1, m) {
        cost[i] = (a[i-1] * i) + b[i-1];
    }
    cout << *(min_element(cost.begin(), cost.end())) << endl;
    return 0;
}   