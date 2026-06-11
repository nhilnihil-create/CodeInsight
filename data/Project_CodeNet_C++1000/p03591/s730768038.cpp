#include<bits/stdc++.h>

using namespace std;
using ll = long long;


int main()
{
    string s; cin >> s;
    cout << ((int)s.size() <= 3 || s.substr(0, 4) != "YAKI" ? "No" : "Yes") << endl;
}