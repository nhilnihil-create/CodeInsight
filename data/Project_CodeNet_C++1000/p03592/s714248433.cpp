#include<bits/stdc++.h>
using namespace std;
using i64 = int_fast64_t;
#define rep(i, N) for(int (i) = 0; (i) < (N); (i)++)
#define all(v) (v).begin(), (v).end()
#define eb emplace_back

int main(){
    int N ,M, K;
    cin >> N >> M >> K;
    bool ok = false;
    rep(n, N+1)rep(m ,M+1)ok |= (K == (N-n)*m + (M-m)*n);
    if(ok) cout << "Yes" << endl;
    else cout << "No" << endl;
}

