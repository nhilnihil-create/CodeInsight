#include <iostream>
#include <bits/stdc++.h>
#include <cstring>
using namespace std;
int main(){
    int count=0;
    string s;
    cin>>s;
    char temp=s[0];
    for(int i=1;i<s.length();i++){
        if(s[i]!=temp){
            count++;
        }
        temp=s[i];
    }
    if (count==0){
        cout<<0;
    }else{
        cout<<count;
    }
    
    return 0;
}