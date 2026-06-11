#include <bits/stdc++.h>
using namespace std;

int main() {
    string S, C, D;
    cin >> S;
    for (int i=0; i<S.length(); i++){
        if (S[i]=='A'){
            C=S.substr(i);
            break;
        }
    }
    reverse(C.begin(), C.end());
    for (int i=0; i<C.length(); i++){
        if (C[i]=='Z'){
            D=C.substr(i);
            break;
        }
    }
    cout << D.length() << endl;
}
