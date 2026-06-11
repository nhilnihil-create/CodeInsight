#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;

typedef pair<ll, pair<int, int> > p;

int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    string S;
    cin >> S;

    vector<int> x(26);

    for(int i = 0; i < S.length(); i++) {
        x[S[i] - 'a']++;
    }

    for(int i = 0; i < 26; i++) {
        if(x[i] > 1) {
            cout << "no" << endl;
            return 0;
        }
    }

    cout << "yes" << endl;
}