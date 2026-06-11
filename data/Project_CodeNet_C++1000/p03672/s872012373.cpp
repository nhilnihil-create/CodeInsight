#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;

typedef pair<int, int> p;

int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    string S;
    cin >> S;

    int ans;

    for(int i = S.length() - 2; i >= 0; i -= 2) {
        bool checker = false;
        for(int j = 0; j < i / 2; j++) {
            if(S[j] != S[i / 2 + j]) {
                checker = true;
                break;
            }
        }
        if(checker) continue;
        ans = i;
        break;
    }

    cout << ans << endl;
}