#include<cstdio>
#include<algorithm>
using namespace std;
using ll = long long;
using ull = unsigned long long;
const static int MOD = 1000000007;

int main(){
    int N, x;
    scanf("%d %d", &N, &x);
    int a[N+1];
    for(int i = 0; i < N; ++i){
        scanf("%d", a + i + 1);
    }
    a[0] = 0;
    ull answer = 0;
    for(int i = 0; i < N; ++i){
        if(a[i] + a[i+1] > x){
            int eat = a[i] + a[i+1] - x;
            a[i+1] -= eat;
            answer += (ull)eat;
        }
    }
    printf("%llu\n", answer);
	return 0;
}