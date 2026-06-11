#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int N, L;
    cin >> N >> L;
    vector<int> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];
    int pos;
    bool check = false;
    for (int i = 1; i < N; i++) {
        if (a[i-1]+a[i] >= L) {
            check = true;
            pos = i;
            break;
        }
    }
    if (!check) {
        cout << "Impossible" << endl;
        return 0;
    }
    cout << "Possible" << endl;
    for (int i = 1; i < pos; i++) cout << i << endl;
    for (int i = N-1; i >= pos; i--) cout << i << endl;
    
    return 0;
}