#include <bits/stdc++.h>
#define rep(i, n) for (int i = 0; i < (n); i++)
using namespace std;

int main(){
    int n; cin >> n;
    int s = 0;
    vector<int> a(n,0);
    rep(i,n){ int x; cin >> x; a[x]++; s = max(s, x); }

    bool check = 1;
    rep(i,s+1){
        if(i < (s+1)/2){ if(a[i] > 0) check = 0; }
        else if(i == (s+1)/2 && s%2){ if(a[i] != 2) check = 0; }
        else if(i == (s+1)/2){ if(a[i] != 1) check = 0; }
        else { if(a[i] < 2) check = 0; }
    }
    cout << (check ? "Possible" : "Impossible") << endl;
    return 0;
}