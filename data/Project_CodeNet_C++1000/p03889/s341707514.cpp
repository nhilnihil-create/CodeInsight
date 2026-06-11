#include <iostream>
#include <algorithm>
#include <iomanip>
#include <vector>
#include <queue>
#include <set>
#include <map>

using namespace std;
typedef long long ll;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    cout << setprecision(10) << fixed;
    string s, t; cin >> s;
    for(int i = s.size()-1; i >= 0; i--){
        char c = s[i];
        if(s[i] == 'b') c = 'd';
        if(s[i] == 'd') c = 'b';
        if(s[i] == 'p') c = 'q';
        if(s[i] == 'q') c = 'p';
        t += c;
    }
    cout << (s == t ? "Yes" : "No") << endl;
}