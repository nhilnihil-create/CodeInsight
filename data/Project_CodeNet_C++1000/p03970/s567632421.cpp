#include<bits/stdc++.h>
using namespace std; 
int main(){
	string s,n="CODEFESTIVAL2016";
    int t;
    cin>>s;
    for(int i=0;i<17;i++){
        if(s[i]!=n[i]) t++;
    }
    cout<<t;
    return 0;
}