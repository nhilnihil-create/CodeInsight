#include <bits/stdc++.h>
using namespace std;
int Search(string t,char s){
    
    int len = t.size();
    for(int i=0;i<len;i++){
        if(t[i] == s) return i;
    }
    
    return -1;
}
int main(void){

    string t = "abcdefghijklmnopqrstuvwyz";
    string s;
    cin >> s;
    int len = s.size();
    
    for(int i=0;i<len;i++){
        if(Search(t,s[i]) != -1) t[Search(t,s[i])] = ' ';
    }
    
    len = t.size();
    for(int i=0;i<len;i++){
        if(t[i] != ' '){
            cout << t[i] << endl;
            return 0;
        }
    }
    
    cout << "None" << endl;
}