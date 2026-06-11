#include<bits/stdc++.h>
using namespace std;

int main() {
    string s; cin >> s;
    int res = 0;
    char pre = s[0];
    for (int i = 1; i < s.size(); i++)
    {
        if(s[i] != pre) {
            pre = s[i];
            res++;
        }
    }
    cout << res << endl;
	return 0;
}
