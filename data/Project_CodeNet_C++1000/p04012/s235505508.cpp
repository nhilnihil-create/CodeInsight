#include <bits/stdc++.h>
using namespace std;

int main(void){
    string w;
    vector<int> cnt(26, 0);
    cin >> w;
    for (int i=0; i<w.size(); i++) cnt[w[i]-'a']++;
    for (int i=0; i<26; i++){
        if (cnt[i]%2 != 0){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    return 0;
}