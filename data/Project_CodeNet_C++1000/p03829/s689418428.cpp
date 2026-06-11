#include <iostream>
#include <string>
#include <set>
#include <algorithm>
#include <cstdio>
#include <vector>
#include <map>
#include <cstring>
#include <cmath>
using namespace std;
#define MAXA 1001
#define MAXB 1001
#define MAXH 1000000001
#define MAXW 1000000007
#define INF 1000000007
#define MAXN 100001
#define MAXM 1001
#define MAXP 1000001
#define MOD 1000000007
typedef long long ll;
typedef pair<int, int> P;

ll N, A, B;
ll X[MAXN];
int main(){
    cin >> N >> A >> B;
    for(int i = 0;i < N;i++){
        cin >> X[i];
    }

    ll ans = 0;
    for(int i = 1;i < N;i++){
        if((X[i] - X[i - 1]) * A < B){
            ans += (X[i] - X[i - 1]) * A;
        }else{
            ans += B;
        }
    }

    printf("%lld\n", ans);
    return 0;
}