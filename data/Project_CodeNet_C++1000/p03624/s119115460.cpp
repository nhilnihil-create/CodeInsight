#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    vector<char> check{'a', 'b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
    vector<bool> judge(check.size(), false);
    for(int i = 0;i < s.size();i++){
        for(int j = 0;j < check.size();j++){
            if(check.at(j) == s.at(i))judge.at(j) = true;
        }
    }
    for(int i = 0;i < judge.size();i++){
        if(!(judge.at(i))){
            cout << check.at(i) << endl;
            return 0;
        }
    }
    cout << "None" << endl;
}
