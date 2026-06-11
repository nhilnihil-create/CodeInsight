#include <bits/stdc++.h>
using namespace std;
using ll = long long;

int main() {
    string s; cin >> s;
    int diff = 0;
    int ans = 0;
    for (int i = 0, N = s.size(); i < N; i++)
    {
        if(diff>0){
            diff--;
            if(s[i]=='g') ans++; 
        } else {
            diff++;
            if(s[i]!='g') ans--; 
        }
    }
    cout << ans << endl;
}