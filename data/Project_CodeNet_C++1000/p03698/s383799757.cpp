#include <bits/stdc++.h>
using namespace std;

int main(void){
    int i,str_length,flag,j;
    string s;
    flag = 0;

    cin >> s;
    str_length = s.size();


    for(i=0; i<str_length - 1; i++){
        for(j=i+1; j<str_length; j++){
            if(s.at(i) == s.at(j)){
                flag = 1;
                break;
            }

        }
        if(flag == 1)   break;
    }

    if(flag == 0){
        cout << "yes" << endl;
    }else if(flag == 1){
        cout << "no" << endl;
    }else{
        cout << "=)"<< endl;
    }

    return 0;
}