#include<bits/stdc++.h>
using namespace std;
using ll = long long;

int main(){
    string s;
    cin >> s;
    cout << s[0] + to_string(s.size() - 2) + s[s.size() - 1] << endl;
}