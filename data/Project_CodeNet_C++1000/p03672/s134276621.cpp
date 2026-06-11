#include <bits/stdc++.h>
using namespace std;
using ll = long long;
using ull = unsigned long long;

bool check(string s) {
    int l = s.length();
    if(l%2==1) return false;
    return(s.substr(0,l/2)==s.substr(l/2)); //s.substr(0,l/2)>>>sの0番目からl/2個抽出
}

int main() {
    string s;
    cin >> s;
    int l = s.length();
    for (int i = l-1;; i--) 
    {
        if(check(s.substr(0,i))) {
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}