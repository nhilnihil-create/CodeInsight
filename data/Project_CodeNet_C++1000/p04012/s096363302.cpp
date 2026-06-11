#include<bits/stdc++.h>
using namespace std;

int main(){
    string w;
    cin >> w;
    
    vector<int> alpha(26);
    for(int i=0; i<26; i++) alpha[i] = 0;

    for(int i=0; i<w.length(); i++){
        alpha[w.at(i) - 'a']++;
    }

    bool flg = true;
    for(int i=0; i<26; i++){
        if(alpha[i]%2 == 1){
            flg=false; break;
        }
    }

    if(flg) cout << "Yes"  << endl;
    else cout << "No" << endl;

    return 0;
}