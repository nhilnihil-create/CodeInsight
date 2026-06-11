#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef unsigned long long ull;
#define REP(i, n) for(int i=0; i<n; i++)
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }
const ll MOD = 1e9+7;

int solve(int left, int right, vector<int>& X){
    int a = X[right];
    if(left != 0) a -= X[left-1];
    int b = right - left + 1 - a;

    int rem = abs(a-b) % 3;
    if(rem == 2) rem = -1;

    if(b > a) rem *= -1;
    return rem;
}

int main(){
    string S, T;
    cin >> S >> T;
    int NS = S.length();
    int NT = T.length();
    vector<int> SA(NS);
    vector<int> TA(NT);
    SA[0] = S[0] == 'A';
    for(int i = 1; i < NS; i++){
        SA[i] = SA[i-1] + (S[i] == 'A');
    }
    TA[0] = T[0] == 'A';
    for(int i = 1; i < NT; i++){
        TA[i] = TA[i-1] + (T[i] == 'A');
    }

    int Q;
    cin >> Q;
    REP(i,Q){
        int a, b, c, d;
        cin >> a >> b >> c >> d;
        a--, b--, c--, d--;

        int aa = solve(a, b, SA);
        int bb = solve(c, d, TA);
        //cout << aa << " " << bb << endl;

        if(aa == bb)
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}
