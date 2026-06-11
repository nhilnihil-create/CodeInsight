#include<bits/stdc++.h>
using namespace std;

#define LL long long
double a, b, c, d, e, f, x, y, ans;
vector<double> u, v;

int main() {
    ios::sync_with_stdio(0), cin.tie(0);
    
    cin >> a >> b >> c >> d >> e >> f;

    for(int i = 0; i <= f; i++) 
        for(int j = 0; j <= f; j++)
            if(100 * i * a + 100 * j * b <= f) u.push_back(100 * i * a + 100 * j * b);

    for(int i = 0; i <= f; i++) 
        for(int j = 0; j <= f; j++)
            if(i * c + j * d <= f) v.push_back(i * c + j * d);

    for(double p : u) {
        for(double q : v) {
            if(p == 0 || q / p > e / 100) continue;
            if(p + q > f) continue;
            if(q / (p + q) >= ans) {
                ans = q / (p + q);
                x = p, y = q;
            }
        }
    }

    cout << x + y << " " << y;
}