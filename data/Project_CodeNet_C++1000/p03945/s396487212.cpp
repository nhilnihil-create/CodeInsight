#include <bits/stdc++.h>

typedef long long   ll;
typedef long double ld;
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    char ref=s[0];
    int ccount=0;
    int n=s.size();
    for(int i = 0; i < n; i++) {
        if(ref!=s[i]){
            ccount++;
            ref=s[i];
        }
    }
    cout << ccount << "\n";
    return 0;
}