#include <bits/stdc++.h>

using namespace std;
int p[100000];


int main(){
    int N, ans = 0;
    cin >> N;
    for(int i=0; i<N; i++) cin >> p[i];

    for(int i=0; i<N-1; i++) {
        if(p[i] == i+1) {
            swap(p[i], p[i+1]);
            ans++;
        }
    }
    if(p[N-1] == N) ans++;
    cout << ans << endl;

    return 0;
}