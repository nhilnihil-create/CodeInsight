#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    string str;
    cin >> str;
    if(str.substr(0, 4) == "YAKI"){
        cout << "Yes" << endl;
    } else {
        cout << "No" << endl;
    }
    return 0;
}