#include <bits/stdc++.h>
using namespace std;
int main(void){
    string s;
    cin >> s;
    set<char> alphabet; 
    
    for (int i=0; i<s.size(); i++) {
        alphabet.insert(s.at(i));
    }
    
    for (int i=0; i<26; i++) {
        char alpha = 'a' + i;
        if (alphabet.count(alpha) == 0) {
            cout << alpha << endl;
            return 0;
        }
    }
    
    cout << "None" << endl;
}
