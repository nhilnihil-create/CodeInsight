#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;

int main(){
    string s;
    cin >> s;
    int a = 0;
    a = s.length() - 2;
    cout << s[0] << a << s[a + 1] << endl; 
}