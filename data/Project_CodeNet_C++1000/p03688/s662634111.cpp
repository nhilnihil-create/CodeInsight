#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    int N;
    cin >> N;
    vector<int> a(N);
    for (int i = 0; i < N; i++) cin >> a[i];
    int nmin = N;
    int nmax = 0;
    for (int i = 0; i < N; i++) {
        nmin = min(nmin, a[i]);
        nmax = max(nmax, a[i]);
    }
    if (nmax-nmin>1) {
        cout << "No" << endl;
    }
    else if (nmax == nmin) {
        if (nmax <= N/2 || nmax == N-1) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
    else{
        int s = count(a.begin(), a.end(), nmin);
        int t = N-s;
        if (t >= 2 && s+1 <= nmax && nmax <= s+t/2) cout << "Yes" << endl;
        else cout << "No" << endl;
    }
        
    return 0;
}