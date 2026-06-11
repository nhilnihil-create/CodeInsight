#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
using P = pair<int,int>;
/* ちゃんと考えてわかって実装 */

int main(void){
    ll n;
    cin >> n;
    vector<ll> A(n);
    for(ll i=0; i<n; i++){
        cin >> A[i];
    }
    sort(A.rbegin(), A.rend());
    ll a, b;
    ll cnt = 0;
    for(int i=0; i<n-1; i++){
        if(A[i] == A[i+1] && cnt == 0){
            a = A[i];
            cnt++;
            i++; // 重複防止
        }
        else if(A[i] == A[i+1] && cnt == 1){
            b = A[i];
            cnt++;
        }
    }
    if(cnt == 2) cout << a * b << endl;
    else cout << 0 << endl;
    return 0;
}