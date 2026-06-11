#include <bits/stdc++.h>
using namespace std;
 
#define ll long long
#define all(aaa) aaa.begin(), aaa.end()
 
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin >> s;

    if (s.size() > 3 && s.substr(0, 4) == "YAKI")
        cout << "Yes\n";
    else
        cout << "No\n";

    return 0;
}