#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;

    int flag = 0;
    if(s.length() <= 3){
        flag = 1;
    }else{
        if(s.substr(0, 4) != "YAKI"){
            flag = 1;
        }
    }

    if(flag == 1){
        cout << "No" << endl;
    }else{
        cout << "Yes" << endl;
    }
}