#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(void){
    ll N, A, B;
    cin >> N >> A >> B;

    ll BA = B - A;

    if(BA < 0) {
        cout << 0 << endl;
        return 0;
    }

    if(N==1){
        if(BA == 0){
            cout << 1 << endl;
            return 0;
        } else {
            cout << 0 << endl;
            return 0;
        }
    }

    ll result = (N-2) * (B-A) + 1;

    cout << result << endl;
    
    return 0;
}
