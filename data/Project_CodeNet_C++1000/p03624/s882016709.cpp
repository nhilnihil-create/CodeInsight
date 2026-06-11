#include<bits/stdc++.h>
using namespace std;
int main(){
    string S;
    cin >> S;
    vector<int> A(26);
    for(int i = 0; i < S.size(); i++){
        A.at(S.at(i) - 'a')++;
    }
    for(int i = 0; i < 26; i++){
        if(A.at(i) == 0){
            cout << char(i + 'a') << endl;
            return 0;
        }
    }
    cout << "None" << endl;
    return 0;
}