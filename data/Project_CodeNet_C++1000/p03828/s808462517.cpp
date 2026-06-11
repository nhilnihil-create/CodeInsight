#include<cstdio>
using namespace std;

const int N_MAX = 1005;
const int MOD = 1000000007;

int divin[N_MAX][N_MAX];

int main(){
    int n;
    scanf("%d", &n);

    for(int i = 2; i <= n; i++)divin[0][i] = 1;


    for(int i = 2; i <= n; i++){
        if (divin[0][i] == -1) continue;

        for(int k = 2 * i; k <= n; k += i) divin[0][k] = -1;
        for(int j = i; j <= n; j++){
            int copj = j;
            int sisu = 0;
            while(copj % i == 0){
                sisu++;
                copj /= i;
            }
            divin[j][i] = sisu;
        }
    }

    long long int ans = 1;
    for(int i = 2; i <= n; i++){
        if (divin[0][i] == -1) continue;
        int total = 0;
        for(int j = i; j <= n; j++) total += divin[j][i];
        ans *= total + 1;
        ans %= MOD;
    }
    printf("%lld\n", ans);
    return 0;
}