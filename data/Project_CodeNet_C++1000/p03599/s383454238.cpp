#include "bits/stdc++.h"

using namespace std;

int A, B, C, D, E, F;

struct SugarWater {
    SugarWater() : sugar(0), water(0) {}
    int sugar;
    int water;
};

const SugarWater ZERO = SugarWater();
double MAX_DENSITY;

double density(SugarWater sw) {
    if (sw.sugar + sw.water == 0) {
        return -1.0;
    }
    else {
        return (double)sw.sugar / (double)(sw.sugar + sw.water);
    }
}

SugarWater dp(SugarWater sw, vector<vector<SugarWater>>& memo) {
    if (sw.sugar + sw.water > F || density(sw) > MAX_DENSITY) {
        return ZERO;
    }
    if (memo[sw.sugar][sw.water].sugar >= 0 && memo[sw.sugar][sw.water].water >= 0) {
        return memo[sw.sugar][sw.water];
    }

    SugarWater op1 = sw;
    SugarWater op2 = sw;
    SugarWater op3 = sw;
    SugarWater op4 = sw;
    op1.water += 100 * A;
    op2.water += 100 * B;
    op3.sugar += C;
    op4.sugar += D;
    op1 = dp(op1, memo);
    op2 = dp(op2, memo);
    op3 = dp(op3, memo);
    op4 = dp(op4, memo);

    SugarWater ret;
    if (density(op1) >= density(op2)
        && density(op1) >= density(op3)
        && density(op1) >= density(op4)
        && density(op1) >= density(sw)) {
        ret = op1;
    }
    else if (density(op2) >= density(op1)
        && density(op2) >= density(op3)
        && density(op2) >= density(op4)
        && density(op2) >= density(sw)) {
        ret = op2;
    }
    else if (density(op3) >= density(op1)
        && density(op3) >= density(op2)
        && density(op3) >= density(op4)
        && density(op3) >= density(sw)) {
        ret = op3;
    }
    else if (density(op4) >= density(op1)
        && density(op4) >= density(op2)
        && density(op4) >= density(op3)
        && density(op4) >= density(sw)) {
        ret = op4;
    }
    else {
        ret = sw;
    }
    memo[sw.sugar][sw.water] = ret;
    return ret;
}

void Main() {
    cin >> A >> B >> C >> D >> E >> F;
    MAX_DENSITY = (double)E / (100.0 + E);
    SugarWater neg;
    neg.sugar = -1;
    neg.water = -1;
    vector<vector<SugarWater>> memo(3000 + 10, vector<SugarWater>(3000 + 10, neg));
    SugarWater ans = dp(SugarWater(), memo);
    cout << (ans.sugar + ans.water) << " " << ans.sugar << endl;
}

int main() {
    std::cout << std::fixed << std::setprecision(15);
    Main();
    return 0;
}
