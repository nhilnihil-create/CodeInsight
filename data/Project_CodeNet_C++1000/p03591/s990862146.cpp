#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    vector<char> S(10);
    string r ="YAKI";
    int i;
    int y=0;
    for(i=0;i<s.size();i++){
        S.at(i)=s.at(i);
    }
    for(i=0;i<4;i++){
        if(S.at(i)!=r.at(i)){
            y++;
        }
    }
    if(y==0){
        cout << "Yes" << endl;
    }
    else{
        cout << "No" << endl;
    }
    return 0;

}