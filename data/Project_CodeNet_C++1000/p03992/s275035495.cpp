#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin>>s;
    for(int i=0;i<=12;i++){
        if(i<=3){
            cout<<s.at(i);
        }else if(i==4){
            cout<<" ";
        }else{
            cout<<s.at(i-1);
        }
    }
    cout<<endl;
return 0;}
/*
g++ code.cpp
./a.out
*/