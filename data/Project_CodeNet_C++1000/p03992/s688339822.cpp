#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);

    string s;
    cin >> s;
    for(int i=0;i<4;i++) cout << s[i];
    cout << ' ';
    for(int i=4;i<12;i++) cout << s[i];
    cout << endl;
    return 0;
}