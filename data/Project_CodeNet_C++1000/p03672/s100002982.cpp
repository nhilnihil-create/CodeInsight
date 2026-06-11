#include<bits/stdc++.h>
typedef long long ll;
using namespace std;

int main() {
    string S;
    cin >> S;
    if(S.size() % 2 == 1) {
        S = S.substr(0, S.size()-1);
    } else {
        S = S.substr(0, S.size()-2);
    }
    while(S.size() > 0) {
        string left = S.substr(0, S.size()/2);
        string right = S.substr(S.size()/2, S.size()/2);
        if(left == right) {
            cout << S.size() << endl;
            return 0;
        } else {
            S = S.substr(0, S.size()-2);
        }
    }
    return 0;
}