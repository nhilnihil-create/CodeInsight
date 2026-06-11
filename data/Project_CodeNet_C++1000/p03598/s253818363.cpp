#include<bits/stdc++.h>
using namespace std;

int main(){
    int N , K, ans = 0;
    cin >> N >> K;
    vector<double> x(N+1);
    for(int i = 1; i <= N; ++i) cin >> x[i];
    for(int i = 1; i <= N; ++i){
        ans += 2 * min(x[i], sqrt(pow(x[i] - K, 2)));
    }
    cout << ans << endl;
    return 0;
}