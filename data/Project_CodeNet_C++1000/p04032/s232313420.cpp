#include<iostream>
#include<string>
#include<map>

using namespace std;;


bool unbalance(string s){
    map<char,unsigned int> score;
    unsigned int i;
    for (auto x : s){
        score[x]++;
        if (score[x] > s.length() / 2){
            return true;
        }
    }
    return false;
}

int main(){
    string input, s;
    bool flag = false;
    cin >> input;

    unsigned int i,j;
    for (j=2; j<=3; j++){
        for  (i=0; i<1+input.length()-j; i++){
            s = input.substr(i, j);
            if (unbalance(s)){
                cout << i + 1 << " " << i + j << endl;
                return 0;
            }
        }
    }
    cout << "-1 -1" << endl;
    return 0;
}