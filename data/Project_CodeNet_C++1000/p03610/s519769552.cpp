#include<bits/stdc++.h>

using namespace std;

#define rep(i, n) for(int i=0; i<(int)(n); i++)

int main() {
    string S;
    cin >> S;

    rep(i, S.size()){
        if(i % 2 == 0) cout << S.at(i);
    }
    cout << endl;
}