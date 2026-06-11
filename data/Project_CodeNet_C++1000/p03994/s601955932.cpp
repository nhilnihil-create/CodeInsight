#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    int k;
    cin >> s >> k;

    int n = s.length();

    for(int i=0; i<n; i++){
        if(s[i] == 'a') continue;

        if('z' - s[i] + 1 <= k){
            k -= ('z' - s[i] + 1);
            s[i] = 'a';
        }
    }

    s[n-1] = 'a' + ((s[n-1] - 'a') + k) % 26;
    cout << s << endl;
    return 0;
}