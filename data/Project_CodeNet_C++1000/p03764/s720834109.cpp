#include <bits/stdc++.h>

using namespace std;
#define rep(i, n) for(int i = 0 ; i < (int)(n) ; i++)
typedef long long ll;
typedef long double Double;

#ifndef INPUTS_DIR
#define INPUTS_DIR "./"
#endif


long long subSolve(vector<ll> v) {
    long long subtractSum = 0;
    long long answer = 0;
    for (int i = 0; i < v.size(); i++) {
        answer += v[i] * i - subtractSum;
        subtractSum += v[i];
        answer %= 1000000007;
    }
    return answer;

}

void solve(ll n, ll m, vector<ll> x, vector<ll> y) {


    cout << subSolve(x) * subSolve(y) % 1000000007 << endl;
}


void main_(istream &cin) {
    ll n;
    ll m;
    cin >> n;
    vector<ll> x(n - 1 + 1);
    cin >> m;
    vector<ll> y(m - 1 + 1);
    for (int i = 0; i <= n - 1; i++) {
        cin >> x[i];
    }
    for (int i = 0; i <= m - 1; i++) {
        cin >> y[i];
    }
    solve(n, m, x, y);
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



