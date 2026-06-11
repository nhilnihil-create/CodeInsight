#include <bits/stdc++.h>
using namespace std;

#define REP(i, start, count) for(int i=(start); i<(int)(count); ++i)
#define rep(i, count) REP(i, 0, count)
#define ALLOF(c) (c).begin(), (c).end()

typedef long long ll;
typedef unsigned long long ull;
typedef vector<int> veci;
typedef vector<long long> vecll;
typedef vector<unsigned long long> vecull;

int N;
string S;

int main(void) {
    stack<char> st;
    int r_cnt = 0;
    cin >> N >> S;

    rep(i, N) {
        if (S[i] == '(') {
            st.push(S[i]);
            continue;
        }
        else {
            if (st.empty())
            {
                r_cnt++;
            }
            else {
                st.pop();
            }
        }
    }

    S = string(r_cnt, '(') + S + string(st.size(), ')');

    cout << S << endl;

    return 0;
}