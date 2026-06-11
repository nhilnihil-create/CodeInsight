#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

string itoa(int x) {
    string ret = "", rev="";
    while (x) {
        rev += (x%10) + '0';
        x /= 10;
    }
    for (int i=rev.size()-1; i>=0; --i) {
        ret += rev[i];
    }
    return ret;
}

void solve() {
    string s;
    string ans = "";
    cin >> s;
    ans += s[0];
    ans += itoa(s.size()-2);
    ans += s[s.size()-1];
    cout<< ans;

}

int main() {

	solve();
    return 0;
}
