#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int,int> iint;
typedef pair<ll,ll> llll;
#define ALL(x) (x).begin(),(x).end()
const ll zero = 0;
const ll one = 1;
const ll INF = 9223372036854775807; //10^18
const int inINF = 2147483647; //10^9
const ll MOD = 1000000007; //10^9+7
const ll MOD2 = 998244353;
void Yes() {printf("Yes\n");}
void No() {printf("No\n");}
void YES() {printf("YES\n");}
void NO() {printf("NO\n");}

int main(){
    int N, K;
    cin >> N >> K;
    vector<int> a(N);
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }
    vector<int> A;
    int cnt = 0;
    for (int i = 0; i < N; i++) {
        if(a[i] < K){
            A.push_back(a[i]);
            cnt ++;
        }
    }
    int ans = N - cnt;
    
    swap(N, cnt);
    vector<vector<bool>> dp1(N+1, vector<bool> (K+1, false));
    vector<vector<bool>> dp2(N+1, vector<bool> (K+1, false));
    for (int i = 0; i < N+1; i++) {
        dp1[i][0] = true;
        dp2[i][0] = true;
    }
    for (int i = 0; i < N; i++) {
        for (int j = K; j >= 0; j--) {
            if(j - A[i] >= 0 && dp1[i][j-A[i]] == true){
                dp1[i+1][j] = true;
            }
            if(dp1[i][j]){
                dp1[i+1][j] = true;
            }
            if(j - A[N-i-1] >= 0 && dp2[i][j-A[N-i-1]] == true){
                dp2[i+1][j] = true;
            }
            if(dp2[i][j]){
                dp2[i+1][j] = true;
            }            
        }
    }

    for (int i = 0; i < N; i++) {
        // dp1[i]とdp2[N-i-1]でK - A_i以上K未満を作れるか判定
        int tmp = 0;
        for (int j = 1; j < A[i]+1; j++) {
            if(dp1[i][K-j]){
                tmp++;
            }
        }
        if(dp2[N-i-1][0] && tmp > 0){
            ans++;
            continue;
        }
        bool check = false;
        for (int j = A[i]+1; j <= K; j++) {
            if(dp1[i][K-j]){
                tmp++;
            }
            if(dp1[i][K-j+A[i]]){
                tmp--;
            }
            if(dp2[N-i-1][j-A[i]] && tmp > 0){
                ans++;
                check = true;
                break;
            }
        }
        if(check) continue;
        for (int j = 0; j < A[i]; j++) {
            if(dp1[i][A[i]-1-j]){
                tmp--;
            }
            if(dp2[N-i-1][K-A[i]+j] && tmp > 0){
                ans++;
                check = true;
                break;
            }
        }
    }
    printf("%d\n", cnt - ans);

}