#include <bits/stdc++.h>
#include <iostream>
#include <string>
using namespace std;
int abs(int x){
    if(x<0) return -x;
    else return x;
}
int main() {
    string s;
    cin>>s;
    int A=0,Z=0;
    for(int i=0;i<s.size();i++){
        if(s[i]=='A'){
            A=i;
            break;
        }
    }
  
    for(int i=s.size()-1;i>0;i--){
        if(s[i]=='Z'){
            Z=i;
            break;
        }
    }
    
    cout<<Z-A+1<<endl;
}