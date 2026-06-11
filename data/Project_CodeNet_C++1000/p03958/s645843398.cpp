#include <bits/stdc++.h>
#define rep(i,n) for (int i = 0; i < (n); ++i)
using namespace std;
typedef long long ll;
typedef pair<int, int> P;

int main() {
    int K, T; cin >> K >> T;
    vector<int> a(T);
    rep(i, T){
        cin >> a[i];
    }
    sort(a.begin(), a.end());

    int total = 0;
    rep(i, T-1){
        total += a[i];
    }

    if(total < a[T-1] - 1){
        cout << a[T-1] - 1 - total << endl; 
    } else {
        cout << 0 << endl;
    }
    

    return 0;
}