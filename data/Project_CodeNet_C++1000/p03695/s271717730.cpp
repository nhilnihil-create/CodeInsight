#include <bits/stdc++.h>
 
using namespace std;

typedef long long ll;

typedef pair<ll, pair<int, int> > p;

int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    int N;
    cin >> N;

    vector<bool> b(8);

    int o = 0;

    for(int i = 0; i < N; i++) {
        int a;
        cin >> a;
        if(a >= 3200) {
            o++;
            continue;
        }
        for(int j = 0; j < 8; j++) {
            if(a < 400 * (j + 1)) {
                b[j] = true;
                break;
            }
        }
    }

    int c = 0;

    for(int i = 0; i < 8; i++) {
        if(b[i]) c++;
    }

    cout << max(1, c) << " " << c + o << endl;
}