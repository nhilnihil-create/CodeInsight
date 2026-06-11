#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;

int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    double A, B, C, D, E, F;
    cin >> A >> B >> C >> D >> E >> F;

    double ans = 0;
    double bns = 0;

    for(int i = 0; i <= 30; i++) {
        for(int j = 0; j <= 30; j++) {
            if(A * 100 * i + B * 100 * j > F) break;
            for(int k = 0; k <= 1500; k++) {
                double x = F - (A * 100 * i + B * 100 * j + C * k);
                double y = (A * 100 * i + B * 100 * j) * E / 100 - C * k;
                if(x < 0) break;
                if(y < 0) break;
                double z = min(x, y);
                int l = z / D;

                double a = A * 100 * i + B * 100 * j + C * k + D * l;
                double b = C * k + D * l;

                if((ans == 0 && bns == 0) || bns / (ans + bns) < b / (a + b)) {
                    ans = a;
                    bns = b;
                }
            }
        }
    }

    cout << ans << " " << bns << endl;
}