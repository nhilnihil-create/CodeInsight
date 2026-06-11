#include<bits/stdc++.h>
#define rep(i, n) for(int i = 0; i < (int)n; i++)
using namespace std;
typedef vector<int> vi;

int main(){
    int N, K;
    cin >> N >> K;
    vi x(N);
    rep(i, N) cin >> x[i];

    int sum = 0;
    rep(i, N){
        sum += min(x[i], K - x[i]);
    }

    cout << sum*2 << endl;

    return 0;
}