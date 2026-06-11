#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for(int i = 0 ; i < (int)(n) ; i++)
typedef long long ll;
typedef long double Double;

#ifndef INPUTS_DIR
#define INPUTS_DIR "./"
#endif


void solve(ll X, ll Y) {
    if (X == Y - 1 || X == Y || X == Y + 1) {
        cout << "Brown" << endl;
    } else {
        cout << "Alice" << endl;
    }

}


void main_(istream &cin) {
    ll Y;
    ll X;
    cin >> X;
    cin >> Y;
    solve(X, Y);
}

int main() {
#ifdef INTELLIJ
    ifstream ifs(string(INPUTS_DIR) + "in_1.txt");
    if (ifs.is_open()) {
        main_(ifs);
        ifs.close();
    } else {
        cerr << "Error: no input." << endl;
    }
#else
    ios::sync_with_stdio(false);
    cin.tie(0);
    main_(cin);
#endif
}



