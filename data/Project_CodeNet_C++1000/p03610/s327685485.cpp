#include <bits/stdc++.h>
using namespace std;
int main(){
    string a; cin >> a;
    string ans = "";
    int i = 0;
    while (i < a.size()){
        ans += a[i];
        i += 2;
    }
    cout << ans << endl;
}