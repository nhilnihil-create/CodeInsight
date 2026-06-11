#include <bits/stdc++.h>
using namespace std;

int main() {
    int n[3];
    for(int i = 0;i<3;i++) cin >> n[i];
    sort(n,n+3,greater<int>());
    if(n[0] == 7 && n[1]== 5 && n[2] == 5) cout << "YES" << endl;
    else cout << "NO" << endl;
}