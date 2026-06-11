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

ll N;
ll A[MAXN];
int main(){
    cin >> N;
    for(int i = 0;i < N;i++){
        cin >> A[i];
    }
    sort(A, A + N);

    ll ans = N, block = 0, in = 1;
    for(int i = 0;i < N - 1;i++){
        if(A[i] == A[i + 1]){
            while(A[i] == A[i + 1]){
                in++;
                i++;
            }
            if(in % 2 == 0){
                block++;
                ans -= in - 2;
            }else{
                ans -= in - 1;
            }
            in = 1;
        }
    }
    ans -= block;
    if(block % 2) ans--;
    printf("%lld\n", ans);
    return 0;
}