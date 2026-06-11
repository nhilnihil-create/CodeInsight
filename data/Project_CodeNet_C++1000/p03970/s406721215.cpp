#include<bits/stdc++.h>
using namespace std;

int main(){
    string s;
    cin >> s;
    string S = "CODEFESTIVAL2016";
    int i;
    int h=0;
    for(i=0;i<s.size();i++){
        if(s.at(i)!=S.at(i)){
            h++;
        }
    }
    cout  << h << endl;
    return 0;
}