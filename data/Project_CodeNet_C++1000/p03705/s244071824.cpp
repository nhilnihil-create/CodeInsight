#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int main(){
    ll N,A,B;
    cin >> N >> A >> B;
    if ((N == 1 && A != B) || (A > B)) {
        cout << 0 << endl;
        return 0;
    }
    cout << (B * N - B + A) - (A * N - A + B) + 1 << endl;
}