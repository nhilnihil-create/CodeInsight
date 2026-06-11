#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int INF = 1e5;

void solve(int N, std::vector<int> s){
    ll total = accumulate(s.begin(), s.end(), 0);
    ll ans;
    if(total % 10 != 0) ans = total;
    else{
        int val = INF;
        for(int i = 0; i < N; ++i){
            if(s[i] % 10 != 0) val = min(val, s[i]);
        }
        if(val == INF) ans = 0;
        else ans = total - val;
    }
    cout << ans << endl;
    return;
}

int main(){
    int N;
    scanf("%id",&N);
    std::vector<int> s(N);
    for(int i = 0 ; i < N ; i++){
        scanf("%id",&s[i]);
    }
    solve(N, std::move(s));
    return 0;
}
