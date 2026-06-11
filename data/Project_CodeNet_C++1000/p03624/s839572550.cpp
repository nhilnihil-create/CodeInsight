#include <bits/stdc++.h>
using namespace std;

int main(){
    string S;
    cin >> S;

    vector<char> s = {'a', 'b', 'c', 'd', 'e', 
                      'f', 'g', 'h', 'i', 'j',
                      'k', 'l', 'm', 'n', 'o',
                      'p', 'q', 'r', 's', 't',
                      'u', 'v', 'w', 'x', 'y', 'z'};

    vector<bool> charFlag(26);

    for(int i = 0; i < S.size(); i++){
        for(int j = 0; j < s.size(); j++){
            if(S.at(i) == s.at(j)){
                charFlag.at(j) = true;
                break;
            }
        }
    }

    bool ansFlag = false;
    for(int i = 0; i < s.size(); i++){
        if(charFlag.at(i) == false){
            cout << s.at(i) << endl;
            ansFlag = true;
            break;
        }
    }

    if(ansFlag == true){

    }else{
        cout << "None" << endl;
    }

}