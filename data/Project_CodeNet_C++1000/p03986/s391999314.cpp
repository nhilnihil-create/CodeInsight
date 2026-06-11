#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

int main() {
    string x; cin >> x;
    stack<char> s;
    for(auto c : x) {
        if(!s.empty() && s.top() == 'S' && c =='T') {
            s.pop();
        }
        else s.push(c);
    }
    cout << s.size() << endl;
}