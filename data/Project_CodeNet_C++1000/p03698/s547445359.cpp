#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    bool judge = true;
    cin >> s;
    for(int i = 0;i < s.size();i++){
        for(int j = i + 1;j < s.size();j++){
            if(s.at(i) == s.at(j))judge = false;
        }
    }
    if(judge)cout << "yes" << endl;
    else cout << "no" << endl;
}