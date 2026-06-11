#include <bits/stdc++.h>
using namespace std;
#define ll long long

int main(){
    string S;
    cin >> S;
    if (S.size() >= 4 && S.substr(0, 4) == "YAKI") cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}