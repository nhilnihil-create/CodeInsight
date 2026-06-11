#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>
#include <set>
#include <map>
using namespace std;

typedef long long ll;
#define rep(i, n) for(int i = 0; i < n; i++)

ll func(int num, int cnt){
    ll ans = 1;
    rep(i, cnt) ans *= num;
    return ans;
}

int main(){
    int N, P;
    cin >> N >> P;
    vector<int> A(N);
    rep(i, N) cin >> A[i];
    int odd_cnt = 0;
    rep(i, N) if(A[i] % 2 == 1) odd_cnt++;
    if(odd_cnt == 0){
        if(P == 1) cout << 0 << endl;
        if(P == 0) cout << func(2, N) << endl;
    }else{
        cout << func(2, N-1) << endl;
    }
    return 0;
}