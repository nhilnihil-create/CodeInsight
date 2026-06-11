#include <bits/stdc++.h>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> A(N);
    for (int i = 0; i < N; i++){
        cin >> A.at(i);
    }
    sort(A.begin(), A.end());
    
    int y = N % 2;
    bool can = true;
    if (y == 0){
        for (int i = 0; i < N; i += 2){
            if (A.at(i) != i + 1){
                can = false;
                break;
            }
            if (A.at(i + 1) != i + 1){
                can = false;
                break;
            }
        }
    }
    else{
        if (A.at(0) != 0) can = false;
        for (int i = 1; i < N; i += 2){
            if (A.at(i) != i + 1){
                can = false;
                break;
            }
            if (A.at(i + 1) != i + 1){
                can = false;
                break;
            }
        }
    }
    int64_t x = 1;
    
    for (int i = 0; i < N / 2; i++){
        x *= 2;
        x %= 1000000007;
    }
    if (can) cout << x << endl;
    else cout << 0 << endl;
}
