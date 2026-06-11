#include<bits/stdc++.h>
using namespace std;
#define int long long
//#undef int
#define mk make_pair
#define pb push_back
#define pf push_front
typedef pair<int, int> pii;
const int mod = 1000000007;
const int INF = 1000000009;
const long long INFL = 1000000000000000018ll;

int N, a[100100];
int sum, dif[100100];

signed main()
{
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> a[i];
        sum += a[i];
    }
    int s = N * (N + 1) / 2;
    if(sum % s){
        printf("NO\n");
        return 0;
    }
    int num = sum / s;
    a[N] = a[0];
    for(int i = 0; i < N; i++){
        dif[i] = a[i + 1] - a[i];///差を取る
        dif[i] -= num;///操作の回数だけ差が+1されていると考えてみると1-Nの回数だけ無駄に-1されることになる。
        if(dif[i] > 0){
            printf("NO\n");
            return 0;
        }
        dif[i] = -dif[i];
        if(dif[i] % N){
            printf("NO\n");
            return 0;
        }
    }
    int cnt = 0;
    for(int i = 0; i < N; i++){
        cnt += dif[i] / N;
    }
    if(cnt == num){
        printf("YES\n");
    }
    else {
        printf("NO\n");
    }


    return 0;
}
/*


*/


