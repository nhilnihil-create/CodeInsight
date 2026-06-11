#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> iint;
typedef pair<ll,ll> llll;
#define ALL(x) (x).begin(),(x).end()
const ll zero = 0;
const ll INF = 3000000000000000000; //10^18
const int inINF = 1000000000; //10^9
const ll MOD = 1000000007; //10^9+7
const ll MOD2 = 998244353;

int main(){
    int A, B, C, D, E, F;
    cin >> A >> B >> C >> D >> E >> F;
    vector<int> water;
    for (int i = 0; i < 31; i++) { //iは操作2の回数
        if(i * B * 100 > F){
            break;
        }
        for (int j = 0; j < 31; j++) {
            if((i * B + j * A) * 100 > F){
                break;
            }
            water.push_back(i * B + j * A);
        }
    }
    sort(ALL(water));
    water.erase(unique(ALL(water)), water.end());
    int N = water.size();
    int ansW, ansS;
    ansW = water[1]; ansS = 0;
    float max_density = 0.0;
    int max_S;
    int ms;

    for (int i = 1; i < N; i++) {
        // water[i] * E と F - 100 * water[i]以下で作れるSの最大値を求める
        max_S = min(water[i] * E, F - 100 * water[i]);

        ms = 0;
        for (int i = 0; i < 1501; i++) {
            if(i * D > max_S){
                break;
            }
            ms = max(ms, i * D + (max_S - i * D) / C * C);
        }

        if( (float)100.0 * ms / (water[i] * 100.0 + ms) > max_density){
            max_density = (float)100.0 * ms / (water[i] * 100.0 + ms);
            ansW = water[i];
            ansS = ms;
        }

    }

    printf("%d %d\n", ansW * 100 + ansS, ansS);


}