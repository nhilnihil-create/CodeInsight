#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using namespace std;
using ll = long long;
int main() {
    int N , gu = 0 , ki = 0;
    cin >> N;
    vector <int> A(N);
    for(int i = 0; i < N; i++){
        cin >> A.at(i);
        if(A.at(i) % 2 == 0){
            gu++;
        }
        else{
            ki++;
        }
    }
    if(ki % 2 == 1){
        cout << "NO" << endl;
    }
    else{
        cout << "YES" << endl;
    }
    return 0;
}
