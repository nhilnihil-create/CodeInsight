#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
    int A, B, C, D, E, F; cin >> A >> B >> C >> D >> E >> F;
    int satoumizu = 100*A;
    int satou = 0;
    double noudo = 0;
    for (int a = 0; a*A*100 <= F; a++){
        for (int b = 0; b*B*100 <= F; b++){
            if(a*A*100 + b*B*100 > F)break;
            int water = a*A*100 + b*B*100;
            for (int c = 0; c < 100; c++){
                for (int d = 0; d < 100; d++){
                    int sugar = C*c + D*d;
                    if(water + sugar > F)break;
                    int tokeru = (water/100) * E;
                    if(sugar > tokeru)break;
                    double noudonow = (100.0*sugar) / (water + sugar);
                    if(noudonow > noudo){
                        noudo = noudonow;
                        satoumizu = water + sugar;
                        satou = sugar;
                    }
                }
            }
        }
    }

    cout << satoumizu << " " << satou << endl;

    return 0;
}