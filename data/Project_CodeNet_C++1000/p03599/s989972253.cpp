#include <bits/stdc++.h>
#include <math.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rrep(i, n) for(int i = (n-1); i >= 0; i--)
using namespace std;
typedef long long ll;
const int MOD = 1000000007;
const ll INF = 1LL<<60;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using Graph = vector<vector<int>>;

typedef pair<int, int> P;


int main(){
    int A, B, C, D, E, F; cin >> A >> B >> C >> D >> E >> F;

    vector<int> waters;
    rep(i,31){
        rep(j,31){
            int water = i*A*100+j*B*100;
            if (water <= F) waters.push_back(water);
        }
    }

    vector<int> sugars;
    rep(i,3001){
        rep(j,3001){
            int sugar = i*C+j*D;
            if (sugar <= F) sugars.push_back(sugar);
        }
    }

    int ans_solution = 0;
    int ans_sugar = 0;
    double concentration = -1.0;
    rep(i,waters.size()){
        rep(j,sugars.size()){
            int solution = waters[i] + sugars[j];
            if (solution > F) continue;
            int dissolve = waters[i]/100*E;
            if (dissolve < sugars[j]) continue;
            double tmp_concentration = 100.0*sugars[j] / solution;
            if (tmp_concentration > concentration){
                concentration = tmp_concentration;
                ans_solution = solution;
                ans_sugar = sugars[j];
            }
        }
    }

    cout << ans_solution << " " << ans_sugar << endl;
}

    