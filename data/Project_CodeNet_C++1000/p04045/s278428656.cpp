#include <bits/stdc++.h>
 
using namespace std;
 
typedef long long ll;
typedef long double ld;
 
typedef pair<int, int> p;
 
int main() {
	cin.tie(0);
    ios::sync_with_stdio(false);

    int N, K;
    cin >> N >> K;

    vector<bool> D(10);

    for(int i = 0; i < K; i++) {
        int d;
        cin >> d;
        D[d] = true;
    }

    for(int i = N; ; i++) {
        int n = i;
        bool checker = false;
        while(n != 0) {
            for(int i = 0; i < 10; i++) {
                if(D[i]) {
                    if(n % 10 == i) {
                        checker = true;
                        break;
                    }
                }
            }
            if(checker) break;
            n /= 10;
        }
        if(checker) continue;
        cout << i << endl;
        return 0;
    }
}