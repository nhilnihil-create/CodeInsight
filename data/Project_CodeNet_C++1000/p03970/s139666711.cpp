#include <bits/stdc++.h>

using namespace std;

int main(){
    string s , res = "CODEFESTIVAL2016";
    cin>>s;
    int c = 0 ;
    for(int i = 0 ; i < s.size() ; ++i){
        if(s[i] != res[i])c++;
    }
    cout<<c<<"\n";
}