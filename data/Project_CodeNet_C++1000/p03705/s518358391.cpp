#include<bits/stdc++.h>
using namespace std;
#define rep (i,n) for (int i = 0; i < (n); i++)
using ll = long long;
template <typename T, typename U>
using P = pair<T,U>;
template <typename T>
using vt = vector<T>;
using vvi = vector<vector<int>>;

int main(){
    ll N,A,B;
    cin >> N >> A >> B;
    if(A > B || A != B && N == 1){
        cout << 0 << endl;
        return 0;
    }

    ll mini = A*(N-1) + B;
    ll maxi = B*(N-1) + A;
    ll ans = maxi - mini + 1;
    cout << ans << endl;
    return 0;
}