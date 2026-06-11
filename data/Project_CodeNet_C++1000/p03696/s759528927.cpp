#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

const int inf = 100000;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    
    string t = "";
    int left = 0;
    int right = 0;
    for (int i = 0; i < S.size(); i++) {
        if (S[i] == '(') {
            left++;
            t += S[i]; 
        } else {
            if (left > 0) {
                t += S[i];
                left--;
                continue;
            } else {
                t = '(' + t;
                t += S[i];
            }
        }
    }
    for (int i = 0; i < left; i++) {
        t += ')';
    }
    cout << t << endl;
}
