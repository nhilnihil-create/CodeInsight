#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;

typedef pair<ll, pair<int, int> > p;

int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    string S;

    cin >> N >> S;

    int left, right;

    left = 0;
    right = 0;

    int la = 0;

    for(int i = 0; i < N; i++) {
        if(S[i] == '(') left++;
        else {
            if(left > 0) left--;
            else la++;
        }
    }

    string ans = "";

    for(int i = 0; i < la; i++) ans += '(';

    ans += S;

    for(int i = 0; i < left; i++) ans += ')';

    cout << ans << endl;
}