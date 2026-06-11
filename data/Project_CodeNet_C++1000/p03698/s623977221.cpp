#include<bits/stdc++.h>
using namespace std;

int main(){
    string S;
    cin >> S;
    unordered_set<char> US;
    for(int i = 0; i <= S.size(); ++i){
        if(US.find(S[i]) != US.end()){
            cout << "no" << endl;
            return 0;
        }
        else US.insert(S[i]);
    }
    cout << "yes" << endl;
    return 0;
}