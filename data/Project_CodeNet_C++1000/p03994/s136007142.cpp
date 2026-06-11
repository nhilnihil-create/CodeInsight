#include <iostream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <string>
#include <map>
#include <queue>
using ll = long long;
using graph = std::vector<std::vector<ll>>;

using namespace std;

int main() {
    string s;
    cin >> s;
    ll K;
    cin >> K;
    int a[s.size()];
    for(int i = 0; i < s.size();i++){
        a[i] = s[i] - 'a';
    }
    for(int i = 0; i < s.size(); i++){
        if(i == s.size() - 1){
            a[i] = (K + a[i]) % 26;
            continue;
        }
        if(a[i] == 0){
            continue;
        }
        if(K >= 26 - a[i]){
            K -= (26 - a[i]);
            a[i] = 0;
        }
    }
    for(int i = 0; i < s.size(); i++){
        cout << (char)('a' + a[i]);
    }
    cout << endl;
}
