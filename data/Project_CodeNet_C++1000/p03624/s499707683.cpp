#include <bits/stdc++.h>
#include <string>
#include <algorithm>
using namespace std;

bool isinclde(string S, char c);

int main(){
    string S;
    cin >> S;

    string alphabets = "abcdefghijklmnopqrstuvwxyz";

    sort(S.begin(), S.end());

    int i=0;
    while(i<alphabets.size()){
        char target = alphabets[i];
        bool is_include = isinclde(S, target);
        if(is_include == false){
            cout << target <<endl;
            return 0;
        }
        i += 1;
    }

    cout << "None" << endl;
    return 0;

}

bool isinclde(string S, char c){
    for(int j=0; j<S.size(); j++){
        if(c == S[j]){
            return true;
        }
    }
    return false;
}