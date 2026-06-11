#include<bits/stdc++.h>
using namespace std;
int main() {
    int n; string s, t; cin >> n >> s >> t;
    int sub = 0;
    for (int i = 0; i < n; i++)
    {
        if(s[i] == t[sub]) sub++;
    }
    cout << 2 * n - sub << endl;
	return 0;
}

