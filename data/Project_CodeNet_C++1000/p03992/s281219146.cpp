#include <bits/stdc++.h>
using namespace std;
 
#define rep(i, n) for (int i = 0; i < (n); i++)

int main(){
    string S;
    cin >> S;
    rep(i,12){
        if(i == 4) cout << " ";
        cout << S[i];
    }
    cout << endl;
    return 0;
}