#include <bits/stdc++.h>

using namespace std;
#define lint long long



int main() {
    string S;
    cin >> S;
    
    int N = S.size();
    
    for(int i = 0; i <= N / 2; ++i){
        if(abs(S[i] - S[N - 1 - i]) == 2 | abs(S[i] - S[N - 1 - i]) == 1 ){
        } else {
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
}