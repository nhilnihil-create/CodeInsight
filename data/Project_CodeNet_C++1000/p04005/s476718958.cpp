#include <bits/stdc++.h>
using namespace std;

int main(){

    long long A, B, C;
    cin >> A >> B >> C;

    long long sufa, sufb, sufc, suf;
    sufc = A*B;
    if(C%2==0) sufc = 0;

    sufb = C*A;
    if(B%2==0) sufb = 0;

    sufa = B*C;
    if(A%2==0) sufa = 0;

    suf = min(sufa, min(sufb, sufc));
    cout << suf << endl;
    return 0;
}