#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <math.h> 
#include <set>
 
using namespace std;
 
#define ll long long int
#define rep(i, n) for(int i = 0; i < n; i++)
#define repp(i, n) for(int i = 1; i <= n; i++)
#define sort(v) sort((v).begin(), (v).end())
using vi = vector<int>;
const int MOD = 1e9 + 7;
 
bool IsPrime(int num){
    if (num < 2) return false;
    else if (num == 2) return true;
    else if (num % 2 == 0) return false; // 偶数はあらかじめ除く
    double sqrtNum = sqrt(num);
    for (int i = 3; i <= sqrtNum; i += 2) { if (num % i == 0) return false; }
    return true;
}
 
int main() {
    int N, M;
    cin >> N >> M;
    bool frag;
    vector<string> A(N);
    vector<string> B(M);
    rep(i, N) cin >> A[i];
    rep(i, M) cin >> B[i];
    rep(i, N - M+1) {
        rep(j, N - M+1) {
            frag = true;
            rep(k, M) {
                if (A[i + k].substr(j, M) != B[k]) {
                    frag = false;
                    break;
                }
            }
            if (frag)break;
        }
        if (frag) break;
    }
    if (frag) cout << "Yes" << endl;
    else cout << "No" << endl;
}