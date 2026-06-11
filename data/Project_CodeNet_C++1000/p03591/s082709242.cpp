#include <bits/stdc++.h>
using namespace std;

int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    string S; cin >> S;
    cout << (4<=S.size()&&S.substr(0,4)=="YAKI"?"Yes":"No") << '\n';
}