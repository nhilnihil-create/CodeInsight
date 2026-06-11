#include <bits/stdc++.h>
using namespace std;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }

int A, B, C, D, E, F;

int main() {
    cin >> A >> B >> C >> D >> E >> F;
    A *= 100; B *= 100;

    long long answater = 0; long long anssugar = 0;
    long double noudo = 0.0;
    for(int i = 0; i*A <= F; ++i) {
        for(int j = 0; j*B <= F-i*A; ++j) {
            long long water = i*A + j*B;
            long long sugarmax = (water/100) * E;
            // cout << "water " << water << " sugar " << sugarmax << endl;
            for(int k = 0; k*C <= sugarmax; ++k) {
                for(int l = 0; l*D <= sugarmax-k*C; ++l) {
                    long long sugar = k*C + l*D;
                    if(sugar <= sugarmax) {
                        if(water+sugar <= F) {
                            long double nownoudo = 100.0*sugar / (water+sugar);
                            if(nownoudo > noudo) {
                                answater = water;
                                anssugar = sugar;
                                noudo = nownoudo;
                            }
                        }
                    }
                }
            }
        }
    }

    if(anssugar == 0 && answater == 0) {
        cout << A << " " << anssugar << endl;
    }else {
        cout << answater+anssugar << " " << anssugar << endl;
    }
}