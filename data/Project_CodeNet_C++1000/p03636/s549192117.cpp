#include <bits/stdc++.h>
#define pb push_back
#define ll long long 
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t = 1; 
    for(int T = 0; T < t ; T++){
        string s;
        cin >> s;
        std::cout << s[0] << s.size() - 2 << s[s.size() - 1]<<  std::endl;
    }
    return 0;
}