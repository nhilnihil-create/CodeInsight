#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin >> s;

    string top = s.substr(0,1);
    string middle = s.substr(1, s.size()-2);
    int m = middle.size();
    string end = s.substr(s.size()-1, 1);
    cout << top << m << end << endl;
}