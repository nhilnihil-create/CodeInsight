#include <bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    vector<bool> alphabet(26,true);
    int num;

    for(int i=0; i<s.size(); i++){
        num=s.at(i)-'a';
        alphabet.at(num)=false;
    }
//    cout << num << endl;
    for(int i=0; i<27; i++){
        if(i<26){
            if(alphabet.at(i)){
            printf("%c\n", (char)(i + 'a'));
            break;
            }
        }
        else cout << "None" << endl;
    }
    
}