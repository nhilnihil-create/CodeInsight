#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
const ll MOD = 1000000007;

int A, B, C, D, E, F, water, sugar;
int x, y;

int main() {
    cin >> A >> B >> C >> D >> E >> F;

    for (int a = 0; a <= F; a += 100*A) {
        for (int b = 0; a+b <= F; b += 100*B) {
            for (int c = 0; a+b+c <= F; c += C) {
                for (int d = 0; a+b+c+d <= F; d += D) {
                    water = a+b;
                    sugar = c+d;
                    if (E*water >= 100*sugar && x*sugar >= y*(water+sugar)) {
                        x = water+sugar;
                        y = sugar;
                    }
                }
            }
        }
    }
    cout << x << " " << y << endl;
}

