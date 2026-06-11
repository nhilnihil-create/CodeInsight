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
    int N, M;
    cin >> N >> M;
    vector<int> X(N);
    for (int i = 0; i < N; i++) {
        cin >> X[i];
    }
    vector<int> A(M, 0);
    for (int i = 0; i < N; i++) {
        A[X[i] % M]++;
    }

    int tmp;
    int ans = 0;
    for (int i = 1; i < M; i++) {
        if(i != M - i){        
            tmp = min(A[i], A[M-i]);
            A[i] -= tmp;
            A[M-i] -= tmp;
        }
        else{
            tmp = A[i] / 2;
            A[i] = A[i] % 2;
        }
        ans += tmp;
    }
    ans += A[0] / 2;
    A[0] = A[0] % 2;

    sort(ALL(X));
    int i = 0;
    while(i < N-1) {
        if(X[i] == X[i+1]){
            tmp = X[i] % M;
            if(A[tmp] >= 2){
                ans++;
                A[tmp] -= 2;
            }
            i++;
        }
        i++;
    }
    printf("%d\n", ans);


}