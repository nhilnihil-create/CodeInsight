#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    string S;
    cin >> N >> S;

    vector<string> start = {"SS", "SW", "WS", "WW"};

    for(auto st : start) {
        string A(N, 'a');
        A.at(0) = st.at(0);
        A.at(1) = st.at(1);
        for(int i = 2; i < N; i++) {
            if(S.at(i - 1) == 'o' && A.at(i - 1) == 'S') {
                A.at(i) = A.at(i - 2);
            } else if(S.at(i - 1) == 'x' && A.at(i - 1) == 'W') {
                A.at(i) = A.at(i - 2);
            } else {
                A.at(i) = (A.at(i - 2) == 'W') ? 'S' : 'W';
            }
        }
        bool a1 = (A.at(N - 1) == 'S');
        bool a2 = (S.at(N - 1) == 'o');
        bool a3 = (A.at(N - 2) == A.at(0));
        if((int(a1 + a2 + a3) % 2) == 0)
            continue;
        bool b1 = (A.at(0) == 'S');
        bool b2 = (S.at(0) == 'o');
        bool b3 = (A.at(N - 1) == A.at(1));

        if(int(b1 + b2 + b3) % 2) {
            cout << A << endl;
            return 0;
        }
    }
    cout << -1 << endl;
}
