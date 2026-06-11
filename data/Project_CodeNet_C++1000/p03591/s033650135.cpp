#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
	string s;
    cin >> s;
    int n = s.size();
    if(n < 4 || s.substr(0, 4) != "YAKI") cout << "No" << endl;
    else cout << "Yes" << endl;
}
