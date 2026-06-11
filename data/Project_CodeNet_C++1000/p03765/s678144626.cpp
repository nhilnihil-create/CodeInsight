#include <bits/stdc++.h>
using namespace std;

int p2[100005];
int p1[100005];

int main(){

    string s, t;
    cin >> s >> t;
    int n = s.size();
    for(int i=1; i<=n; i++){
        p1[i] = p1[i-1] + 1;
        if(s[i-1] == 'A') p1[i]++;
    }
    n = t.size();
    for(int i=1; i<=n; i++){
        p2[i] = p2[i-1] + 1;
        if(t[i-1] == 'A') p2[i]++;
    }
    int q;
    cin >> q;
    while(q--){
        int l1, r1, l2, r2;
        cin >> l1 >> r1 >> l2 >> r2;
        int a = (p1[r1] - p1[l1-1])%3;
        int b = (p2[r2] - p2[l2-1])%3;
        if(a == b){
            cout << "YES\n";
        }
        else cout << "NO\n";
    }
    return 0;
}
