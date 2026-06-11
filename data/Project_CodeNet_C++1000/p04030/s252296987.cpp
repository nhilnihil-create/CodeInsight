#include <iostream>
#include <vector>
using namespace std;

int main(){
    vector<char>S;
    string s; cin >> s;

    for(int i=0; i<s.size(); i++){
        if(s[i]!='B'){
            S.push_back(s[i]);
        } else {
            if(S.size()!=0) S.pop_back();
        }
    }

    for(int i=0; i<S.size(); i++){
        cout << S[i];
    }    
    cout << endl;

    return 0;
}