#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
    ll A, B, C;
    cin >> A >> B >> C;
    ll count = 0;
    while(A % 2 == 0 && B % 2 == 0 && C % 2 == 0){
        ll tmp_A = A, tmp_B = B, tmp_C = C;
        A += tmp_B / 2 + tmp_C / 2;
        B += tmp_A / 2 + tmp_C / 2;
        C += tmp_A / 2 + tmp_B / 2;
        count ++;
        if(A == B && A == C){
            cout << -1 << endl; return 0;
        } 
    }
    cout << count << endl;
}