#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define rep(i, n) for(int i = 0; i < n; i++)

static const int INFTY = 1e+9 + 7;

int power(int a, int n){
    if(n == 0) return 1;
    if(a == 0) return 0;
    return (a * power(a, n - 1)) % INFTY;
}

int main(){
    int n; cin >> n;
    vector<int> A(n);
    rep(i, n) cin >> A[i];
    sort(A.begin(), A.end());

    bool flag = true;
    if(n % 2){
        if(A[0] != 0) flag = false;
        rep(i, n / 2){
            if(A[2 * i + 1] != 2 * (i + 1)) flag = false;
            if(A[2 * i + 2] != 2 * (i + 1)) flag = false;
        }
    } else
        rep(i, n / 2){
            if(A[2 * i + 0] != 2 * i + 1) flag = false;
            if(A[2 * i + 1] != 2 * i + 1) flag = false;
        }

    if(flag) cout << power(2, n / 2) << endl;
    else cout << 0 << endl;

    return 0;
}