#include<bits/stdc++.h>
using namespace std;

int main(){
    int N, A, B, n = 0, f = 0;
    string S;
    cin >> N >> A >> B >> S;
    for(int i = 0; i < N; ++i){
        if(S[i] == 'a' && n < A+B){
            ++n;
            cout << "Yes" << endl;
        }
        else if(S[i] == 'b' && n < A+B && f < B){
            ++n;
            ++f;
            cout << "Yes" << endl;
        }
        else{
            cout << "No" << endl;
        }
    }
    return 0;
}