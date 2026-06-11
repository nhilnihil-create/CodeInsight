#include <bits/stdc++.h>
using namespace std;

int main(void){
    string s;
    int cnt[26] = {0};
    cin >> s;
    for (int i=0; i<s.size(); i++){
        if (cnt[s[i]-'a'] == 1){
            cout << "no" << endl;
            return 0;
        } else{
            cnt[s[i]-'a'] = 1;
        }
    }
    cout << "yes" << endl;
    return 0;
}
