#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    cin >> s;
    int indexN=-1,indexW=-1,indexE=-1,indexS=-1;
    for(int i = 0; i < s.length(); i++){
        if(s[i]=='N')indexN=i+1;
        if(s[i]=='W')indexW=i+1;
        if(s[i]=='S')indexS=i+1;
        if(s[i]=='E')indexE=i+1;
    }
    if(indexN*indexS<0){
        cout << "No" << endl;
        return 0;
    }
    if(indexW*indexE<0){
        cout << "No" << endl;
        return 0;
    }
    cout << "Yes" << endl;
    return 0;
}