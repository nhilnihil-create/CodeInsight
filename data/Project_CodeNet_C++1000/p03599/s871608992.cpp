#define _GLIBCXX_DEBUG
#include <bits/stdc++.h>
using namespace std;

#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define all(v) v.begin(), v.end()
#define Graph vector<vector<int>>
typedef long long ll;
const int INF = 1000000007;

// #include <boost/multiprecision/cpp_dec_float.hpp>
// #include <boost/multiprecision/cpp_int.hpp>
// namespace mp = boost::multiprecision;
// using Bint = mp::cpp_int;
// using Real = mp::number<mp::cpp_dec_float<1024>>;

int main(){
    int A, B, C, D, E, F;
    cin >> A >> B >> C >> D >> E >> F;
    int sugar_max = (3000 / (100 + E)) * E;

    set<int> sugar, water;
    for(int i = 0; i <= sugar_max/C; i++){
        for(int j = 0; j <= sugar_max/D; j++){
            int tmp = i * C + j * D;
            if(tmp <= sugar_max) sugar.insert(tmp); 
        }
    }

    for(int i = 0; i <= 30/A; i++){
        for(int j = 0; j <= 30/B; j++){
            int tmp = (i * A + j * B) * 100;
            if(tmp <= F && tmp >= 100) water.insert(tmp); 
        }
    }

    int ans_water = 0, ans_sugar = 0;
    double ans_c = -1;
    for(int w : water){
        for(int s : sugar){
            double tmp_c = (double)(s) / (double)(s + w);
            if(w + s <= F && s <= w / 100 * E && tmp_c > ans_c){
                ans_sugar = s;
                ans_water = w;
                ans_c = (double)(ans_sugar) / (double)(ans_water + ans_sugar);
            }
        }
    }

    cout << ans_sugar + ans_water << ' ' << ans_sugar << endl;
}