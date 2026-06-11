#include<bits/stdc++.h>
using namespace std;

int main(){
    vector<string> word(3);
    for(int i = 0;i < 3;i++)cin >> word.at(i);
    vector<char> compare{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    vector<char> ANS{'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z'};
    for(int i = 0;i < 3;i++){
        for(int j = 0;j < compare.size();j++){
            if(word.at(i).at(0) == compare.at(j)){
                cout << ANS.at(j);
                break;
            }
        }
    }
    cout << endl;
}