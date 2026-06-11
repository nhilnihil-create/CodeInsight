#include<iostream>
using namespace std;
int main(){
    string s, ans;
    cin >> s;
    ans = s[0];
    ans += s[s.size() - 1];
    s.erase(s.size() -1);
    s.erase(0, 1);
    ans.insert(1, to_string(s.size()));
    cout << ans << endl;
}