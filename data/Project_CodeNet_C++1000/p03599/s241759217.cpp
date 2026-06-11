#include <bits/stdc++.h>
#include <math.h>
#define rep(i, n) for(int i = 0; i < (n); i++)
#define rrep(i, n) for(int i = 0; i <= (n); i++)
using namespace std;
typedef long long ll;
 
const ll INF = 1LL<<60;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
using Graph = vector<vector<int>>;

typedef pair<int, int> P;
typedef priority_queue<int, vector<int>, greater<int>> PQ;
const int MOD = 1000000007;


int main(){

    int A, B, C, D, E, F;
    cin >> A >> B >> C >> D >> E >> F;
    vector<int> waters;
    for(int i = 0; i <= F/100; i++){
        for (int j = 0; j <= F/100; j++){
            int water = i*A*100 + j*B*100;
            if (water <= F){
                waters.push_back(water);
            }
        }
    }

    vector<int> sugars;
    for (int i = 0; i <= F; i++){
        for(int j = 0; j <= F; j++){
            int sugar = i*C + j*D;
            if (sugar <= F){
                sugars.push_back(sugar);
            }
        }
    }

    int ans_sugar_water = 0;
    int ans_sugar = 0;
    double max_concentration = -1.0;
    for(int i = 0; i < waters.size(); i++){
        for (int j = 0; j < sugars.size(); j++){
            int water_sugar = waters[i] + sugars[j];
            if (water_sugar <= F){
                int dissolve_amount = waters[i] / 100 * E;
                if (dissolve_amount >= sugars[j]){
                    double concentration = 100.0*sugars[j]/(water_sugar);
                    if (max_concentration < concentration){
                        max_concentration = concentration;
                        ans_sugar_water = water_sugar;
                        ans_sugar = sugars[j];
                    }
                }
            }
        }
    }

    cout << ans_sugar_water << " " << ans_sugar << endl;
}