#include<bits/stdc++.h>
#define rep(i,n) for(int i = 0; i < (n); i++)
using namespace std;
typedef long long ll;

int main() {
    string S;
    cin >> S;
    vector<char> v = {'Y','A','K','I'};
    vector<char> vec(4);
    rep(i,4) {
        vec[i] = S[i];
    }
    if (vec==v) {
        cout << "Yes" << endl;
    }
    else {
        cout << "No" << endl;
    }
}