#include <bits/stdc++.h>
using namespace std;
typedef long long ll;


int main(){
    ll A, B;
    cin >> A >> B;
    if(A * B < 0 || A == 0 || B == 0){
        cout << "Zero" << endl;
    }else if(A < 0 && B < 0 && (abs(A) - abs(B) + 1) % 2 == 1 ){
        cout << "Negative" << endl;
    }else{
        cout << "Positive" << endl;
    }
}