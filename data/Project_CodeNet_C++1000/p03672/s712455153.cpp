#include <bits/stdc++.h>
#define rep(i, n) for (ll i = 0; i < (n); i++)
#define all(x) (x).begin(), (x).end()
using ll = long long;
using namespace std;
template <typename T> using vec = std::vector<T>;

int main() {
    string S;
    cin >> S;
    int N = S.size();
    int ans = 0;
    for(int i=1;i<N/2;++i){
        bool flag = true;
        for(int j=0;j<i;++j){
            if(S[j] != S[j+i]) flag = false;
        }
        if(flag) ans = max(ans,i*2);
    }
    cout << ans << endl;
}
