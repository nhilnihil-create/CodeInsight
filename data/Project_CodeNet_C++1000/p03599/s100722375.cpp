#include <bits/stdc++.h>

using namespace std;
typedef long long ll;

int a, b, c, d, e, f;
int tot=-1, tok=1;
void solve()
{
     cin >> a >> b >> c >> d >> e >> f;
     for(int i = 0; i * a * 100 <= f; i++){
        for(int j = 0; j * b * 100 <= f - i * a * 100; j++){
            int water = i * a * 100 + j * b * 100;
            if(water == 0) continue;
            for(int r = 0; r * c <= f - water; r++){
                for(int k = 0; k * d <= f - water - r * c;k++){
                        int sugarsum = k * d + r * c;
                        int sum = water + sugarsum;
                        int real = i * a * e + j * b * e;
                        if(real < sugarsum || sum >f)  continue;
                    if(sugarsum * 1.0 / sum > tok *1.0 / tot ){
                         tot = sum;
                         tok=sugarsum;
                    }
                }
            }
        }
     }
     cout<< tot <<" "<< tok <<endl;
}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);
    solve();
    return 0;
}
