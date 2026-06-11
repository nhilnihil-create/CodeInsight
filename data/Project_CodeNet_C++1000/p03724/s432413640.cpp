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
    int N , M;
    cin >> N >> M;
    vector<int> A(N+1, 0);
    int a, b;
    for (int i = 0; i < M; i++) {
        cin >> a >> b;
        A[a]++;
        A[b]++;
    }

    for (int i = 1; i < N+1; i++) {
        if(A[i] % 2 == 1){
            printf("NO\n");
            return 0;
        }
    }
    printf("YES\n"); return 0;
}