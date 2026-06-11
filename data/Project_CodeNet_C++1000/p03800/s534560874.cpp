#include <iostream>
#include <string>
#include <vector>

using namespace std;

int N;
string s;

bool f(vector<int> &t) {
    for(int i=1; i<=N; i++) {
        if(s[i] == 'o' && t[i]) {
            t[i+1] = 1 - t[i-1];
        } else if(s[i] == 'o') {
            t[i+1] = t[i-1];
        } else if(t[i]) {
            t[i+1] = t[i-1];
        } else {
            t[i+1] = 1 - t[i-1];
        }
    }
    if(t[0] == t[N] && t[1] == t[N+1]) {
        for(int i=0; i<N; i++) {
            if(t[i]) {
                cout << 'W';
            } else {
                cout << 'S';
            }
        }
        cout << endl;
        return true;
    } else {
        return false;
    }
}

int main(void) {
    cin >> N >> s;
    s.push_back(s[0]);
    s.push_back(s[1]);
    vector<int> t(N+2);

    t[0] = 0;
    t[1] = 0;
    if(f(t)) return 0;
    t[0] = 0;
    t[1] = 1;
    if(f(t)) return 0;
    t[0] = 1;
    t[1] = 0;
    if(f(t)) return 0;
    t[0] = 1;
    t[1] = 1;
    if(f(t)) return 0;
    cout << -1 << endl;
    return 0;
}
