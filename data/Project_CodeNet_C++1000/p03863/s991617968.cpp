#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<(n); i++)
typedef long long ll;

int main(){
    string s;
    cin >> s;
    if ((s.size()%2==0 && s[0] != s[s.size()-1]) || (s.size()%2!=0 && s[0] == s[s.size()-1])) {
        cout << "Second" << endl;
    } else {
        cout << "First" << endl;
    }
    return 0;
}