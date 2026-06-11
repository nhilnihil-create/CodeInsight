#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD = 1000000007;

int main(){
    ll N, L; cin >> N >> L;
    vector<ll> A(N); for(int i = 0; i < N; i++) cin >> A[i];
    ll Max = 0;
    int idx = -1;
    for(int i = 0; i < N-1; i++) {
        ll temp = A[i]+A[i+1];
        if(Max < temp){
            Max = temp;
            idx = i;
        }
    }
    if(Max < L){
        cout << "Impossible" << endl;
        return 0;
    }
    cout << "Possible" << endl;
    idx++;
    for(int i = 1; i < idx; i++){
        cout << i << endl;
    }
    for(int i = N-1; i > idx; i--){
        cout << i << endl;
    }
    cout << idx << endl;

}
