#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i = 0; i < (int)(n); i++)
#define repr(i,n) for(int i = (int)(n); i >= 0; i--)
#define all(v) v.begin(),v.end()
typedef long long ll;

int main(){
    double A,B,C,D,E,F;
    cin >> A >> B >> C >> D >> E >> F;
    vector<double> water(0);
    vector<double> sugar(0);
    rep(i,31){
        rep(j,31){
            if (i == 0 && j == 0) continue;
            else if (i * 100 * A + j * 100 * B <= F){
                water.push_back(i * 100 * A + j * 100 * B);
            }
        }
    }
    rep(i,3001){
        rep(j,3001){
            if (i * C + j * D <= F){
                sugar.push_back(i * C + j * D);
            }
        }
    }
    double max_density = 0;
    pair<double, double> ans;
    ans.first = 0;
    ans.second = 0;
    int len_water = water.size();
    int len_sugar = sugar.size();
    rep(i,len_water){
        rep(j,len_sugar){
            double density = sugar[j] * 100 / water[i];
            if (water[i] + sugar[j] <= F && density <= E){
                if (max_density <= density){
                    ans.first = water[i];
                    ans.second = sugar[j];
                    max_density = density;
                }
            }
        }
    }
    cout << ans.first + ans.second << " " << ans.second << endl;
}
