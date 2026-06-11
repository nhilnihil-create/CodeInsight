#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
typedef pair<int, int> p;
 
int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    string S;
    cin >> N >> S;

    int ans = 0;

    int x = 0;

    for(int i = 0; i < N; i++) {
        if(S[i] == 'I') x++;
        else x--;
        ans = max(ans, x);
    }

    cout << ans << endl;
}