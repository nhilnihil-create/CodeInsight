#include <bits/stdc++.h>
#define rep(i, n) for (int i=0; i<(n); ++i)
#define repr(i, a, b) for (int i=a; i<(b); ++i)
#define reprev(i, n) for (int i=n-1; i>=0; --i)
#define reprrev(i, a, b) for (int i=b-1; i>=(a); --i)
using namespace std;
using ll = long long;
using P = pair<int, int>;

int main() {
    cout << fixed << setprecision(10);

    double E;
    int A, B, C, D, F; cin >> A >> B >> C >> D >> E >> F;
    E /= 100;
    A *= 100;
    B *= 100;

    // 100*A[g]水, 100*B[g]水, C[g]砂糖, D[g]砂糖, 濃度上限E[g]の砂糖/100[g]水, 質量上限F[g]の(砂糖+水)

    // 有りうる水をあげる
    vector<int> water;
    vector<int> olw(F+1);
    // cout << "water" << endl;
    olw[0] = 1;
    for (int i = 0; i <= F; i += A) {
        // cout << "i " << i << endl;
        for (int j = 0; j+i <= F; j += B) {
            // cout << "j " << j << endl;
            if (olw[i+j] == 0) {
                water.emplace_back(i+j);
                // cout << i+j << " i+j" << endl;
                olw[i+j] = 1;
            }
        }
    }
    // cout << endl;
    // cout << "sugar" << endl;
    vector<int> sugar;
    vector<int> ols(F+1);
    // ols[0] = 0;
    for (int i = 0; i <= F; i += C) {
        for (int j = 0; i+j <= F; j += D) {
            if (ols[i+j] == 0) {
                // cout << i+j << " ";
                sugar.emplace_back(i+j);
                ols[i+j] = 1;
            }
        }
    }
    // cout << endl;
    sort(sugar.begin(), sugar.end());

    double max_noudo = -1.0;
    int max_total = 0;
    int max_sugar = 0;

    rep(i, water.size()) {
        rep(j, sugar.size()) {
            int total = water[i] + sugar[j];
            double wari = sugar[j] / double(water[i]);
            if (total > F || wari > E) break;
            double noudo = sugar[j] / double(water[i] + sugar[j]);
            if (noudo > max_noudo) {
                max_total = sugar[j] + water[i];
                max_sugar = sugar[j];
                max_noudo = noudo;
            }
        }
    }

    cout << max_total << " " << max_sugar << endl;

    /*
    // 三つの要素を持つdp そのgに存在するか、水のg、砂糖のg
    vector<vector<int>> dp(F+1, vector<int>(3));
    dp[0][0] = 1;

    repr(ug, 1, F+1) {
        // 水をA入れる
        double bnoudo = -1.0;
        if (dp[ug][1] > 0) {
            // 水が存在すれば、濃度を計算
            bnoudo = dp[ug][2] / double(dp[ug][1] + dp[ug][2]);
        }
        if (ug - A >= 0 && dp[ug-A][0] == 1) {
            // cout << ug << " A" << endl;
            // 入れた後の濃度
            double anoudo = double(dp[ug-A][2]) / (dp[ug-A][2] + dp[ug-A][1] + A);
            if (bnoudo > anoudo + EPS) continue; // 前の濃度の方が高ければ、
            // cout << ug << " A" << endl;
            dp[ug][0] = 1;
            dp[ug][1] = dp[ug-A][1] + A;
            dp[ug][2] = dp[ug-A][2];
        }
        if (ug - B >= 0 && dp[ug-B][0] == 1) {
            double anoudo = double(dp[ug-B][2]) / (dp[ug-B][2] + dp[ug-B][1] + B);
            if (bnoudo > anoudo + EPS) continue; // 前の濃度の方が高ければ、
            // cout << ug << " B" << endl;
            dp[ug][0] = 1;
            dp[ug][1] = dp[ug-B][1] + B;
            dp[ug][2] = dp[ug-B][2];
        }
        if (ug - C >= 0 && dp[ug-C][0] == 1 && dp[ug-C][1] > 0) {
            double anoudo = double(dp[ug-C][2] + C) / (dp[ug-C][2] + dp[ug-C][1] + C);
            double asato = (dp[ug-C][2] + C) / double(dp[ug-C][1]);
            if (bnoudo > anoudo + EPS || asato > E + EPS) continue;
            dp[ug][0] = 1;
            dp[ug][1] = dp[ug-C][1];
            dp[ug][2] = dp[ug-C][2] + C;
            if (max_noudo + EPS < anoudo) {
                max_noudo = anoudo;
                bnoudo = anoudo;
                ans_i = ug;
            }
        }
        if (ug - D >= 0 && dp[ug-D][0] == 1 && dp[ug-D][1] > 0) {
            double anoudo = double(dp[ug-D][2] + D) / (dp[ug-D][2] + dp[ug-D][1] + D);
            double asato = (dp[ug-D][2] + D) / double(dp[ug-D][1]);
            if (bnoudo > anoudo + EPS || asato > E + EPS) continue;
            dp[ug][0] = 1;
            dp[ug][1] = dp[ug-D][1];
            dp[ug][2] = dp[ug-D][2] + D;
            if (max_noudo + EPS < anoudo) {
                max_noudo = anoudo;
                ans_i = ug;
            }
        }
        // cout << ug << " " << dp[ug][1] << " " << dp[ug][2] << endl;
    }
    cout << dp[ans_i][1] + dp[ans_i][2] << " " << dp[ans_i][2] << endl;
    */
    return 0;
}