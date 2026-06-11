#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
    int N; cin >> N;
    int tuyoi = 0;
    vector<int> C(8);
    rep(i, N){
        int a; cin >> a;
        int x = a / 400;
        if(x < 8){
            C[x]++;
        } else {
            tuyoi++;
        }
    }

    int ans = 0;
    rep(i, 8){
        if(C[i] != 0)ans++;
    }
    if(ans == 0){
        ans = 1;
        tuyoi--;
    }

    cout << ans << " " << ans + tuyoi << endl;


    return 0;
}