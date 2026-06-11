#include <iostream>
#include <bits/stdc++.h>
using namespace std;
int main(void){
    string s;
    cin>>s;
    int l=0;
    int r = s.size();
    for (int i = 0;i<s.size();i++){
        char c = s[i];
        if (c!='A'){
            l++;
        }
        else{
            break;
        }
    }
    for (int i=s.size()-1;i>=0;i--){
        char c = s[i];
        if (c!='Z'){
            r--;
        }
        else{
            break;
        }
    }
    cout<<r-l;

    
}
