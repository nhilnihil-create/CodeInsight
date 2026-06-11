#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
typedef pair<int, int> p;
 
int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<int> T(N);

    int sum = 0;

    for(int i = 0; i < N; i++) {
        cin >> T[i];
        sum += T[i];
    }

    int M;
    cin >> M;

    vector<int> ans(M);

    for(int i = 0; i < M; i++) {
        int P, X;
        cin >> P >> X;
        P--;
        ans[i] = sum + X - T[P];
    }

    for(int i = 0; i < M; i++) cout << ans[i] << endl;
}