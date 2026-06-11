#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < n; i++)
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)
using namespace std;
using Graph = vector<vector<int>>;
#define MOD 1000000007
#define MOD2 998244353
#define INF ((1<<30)-1)
#define LINF (1LL<<60)
#define EPS (1e-10)
typedef long long ll;
typedef pair<ll, ll> P;

int main(){
    int A, B, C, D, E, F;
    cin >> A >> B >> C >> D >> E >> F;
    long double dens = 0;
    int Water = 100 * A, Suger = 0;
    for(int a = 0; a <= F; a += 100*A){
        for(int b = a; b <= F; b += 100*B){
            for(int c = 0; c <= F - b; c += C){
                for(int d = c; d <= F - b; d += D){
                    if (b * E < d * 100 || b + d > F) continue;
                    int water = b;
                    int suger = d;
                    long double tmp = double(d) / double(b + d);
                    if(tmp > dens) Water = water, Suger = suger, dens = tmp;
                }
            }
        }
    }

    cout << Water + Suger << " " << Suger << endl;

    return 0;
}