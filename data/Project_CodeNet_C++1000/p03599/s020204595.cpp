#include <bits/stdc++.h>
#define rep(i, z, n) for(int i = z; i < n; i++)
#define all(v) v.begin(), v.end()
typedef long long ll;
const int INF = 1<<29;
//const int MODINF = 1000000007;
using namespace std;

int main(){
    int A, B, C, D, E, F;
    cin >> A >> B >> C >> D >> E >> F;
    vector<double> X(0), Y(0);
    for (int i = 0; i * 100 * A <= F; i++){
        for (int j = 0; j * 100 * B + i * 100 * A <= F; j++){
            X.push_back(j * 100 * B + i * 100 * A);
        }
    }
    for (int i = 0; i * C <= F; i++){
        for (int j = 0; j * D + i * C <= F; j++){
            Y.push_back(j * D + i * C);
        }
    }
    
    int ansSW = 100 * A, ansS = 0;
    double per = 0;
    rep(i, 0, X.size()){
        rep(j, 0, Y.size()){
            if (X.at(i) + Y.at(j) > F) continue;
            if (X.at(i) * E < 100 * Y.at(j)) continue;
            if (Y.at(j) * 100 > (X.at(i) + Y.at(j)) * per){
                per = Y.at(j) * 100 / (X.at(i) + Y.at(j));
                ansSW = X.at(i) + Y.at(j);
                ansS = Y.at(j);
            }
            //cout << fixed << setprecision(5) << per << " ";
            //cout << X.at(i) << " " << Y.at(j) << " " << ansSW << " " << ansS << endl;
        }
    }
    cout << ansSW << " " << ansS << endl;
}