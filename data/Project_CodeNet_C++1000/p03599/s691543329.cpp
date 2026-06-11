#include <iostream>
using namespace std;
int main(){
    int A, B, C, D, E, F;
    cin >> A >> B >> C >> D >> E >> F;
    int lima = F / (100*A);
    int sum = lima * A * 100;
    int ans = 0;
    for(int i = 0; i <= lima; i++){
        int limb = (F - (100*A*i)) / (100*B);
        for(int j = 0; j <= limb; j++){
            int limsu = (A * i + B * j) * E;
            int water = (A * i + B * j) * 100;
            int limf = F - water;
            int limc = min(limf / C, limsu / C);
            for(int k = 0; k <= limc; k++){
                int d = min((limf - C * k) / D, (limsu - C * k) / D);
                int s = water + C * k + D * d;
                int temp = C * k + D * d;
                int res1 = ans * s, res2 = temp * sum;
                if(res1 < res2){
                    ans = temp;
                    sum = s;
                }
            }
        }
    }
    cout << sum << ' ' << ans << endl;
}