#include <bits/stdc++.h>
using namespace std;
/* typedef */
typedef long long ll;
typedef pair<int, int> pii;
/* constant */
const int INF = 1 << 30;
const ll LINF = 1LL << 50;
const int NIL = -1;
const int MAX = 10000;
const int mod = 1000000007;
const double pi = 3.141592653589;
/* global variables */
/* function */
/* main */
int main(){
    string S;
    cin >> S;
    S += ".";
    vector<pair<char, int> > v;
    int cnt = 1;
    for (int i = 0; i < S.size() - 1; i++) {
        if (S[i] == S[i+1]) cnt++;
        else {
            v.push_back(make_pair(S[i], cnt));
            cnt = 1;
        }
    }
    cout << v.size() - 1 << '\n';
}
