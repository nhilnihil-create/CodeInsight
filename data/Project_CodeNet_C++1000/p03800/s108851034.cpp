#include <bits/stdc++.h>
using namespace std;

int main() {
    int N;
    cin >> N;
    string S;
    cin >> S;
    
    // false: wolf  true: sheep
    for(int i=0; i<4; ++i) {
        vector<bool> a(N);
        a[0] = i % 2;
        a[1] = (i >> 1) % 2;

        for(int i=1; i+1<N; ++i) {
            if((S[i] == 'o') ^ a[i]) a[i + 1] = !a[i - 1];
            else a[i + 1] = a[i - 1];
        }

        if(a[0]) {
            if(S[0] == 'o' && a[N-1] != a[1]) continue;
            if(S[0] == 'x' && a[N-1] == a[1]) continue; 
        } else {
            if(S[0] == 'o' && a[N-1] == a[1]) continue;
            if(S[0] == 'x' && a[N-1] != a[1]) continue; 
        }

        if(a[N-1]) {
            if(S[N-1] == 'o' && a[N-2] != a[0]) continue;
            if(S[N-1] == 'x' && a[N-2] == a[0]) continue; 
        } else {
            if(S[N-1] == 'o' && a[N-2] == a[0]) continue;
            if(S[N-1] == 'x' && a[N-2] != a[0]) continue; 
        }

        for(int i=0; i<N; ++i) cout << (a[i] ? 'S' : 'W');
        cout << endl;
        return 0;
    }

    cout << -1 << endl;
}