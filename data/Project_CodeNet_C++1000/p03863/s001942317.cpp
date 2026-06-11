#include<bits/stdc++.h>
using namespace std;
int i,j,k,m,n;
string s;
int main(){
    getline(cin,s);
    int len=s.size();
    if(s[0]==s[len-1]){
        if(len%2==1)cout<<"Second"<<endl;
        else cout<<"First"<<endl;
    }
    else {
        if(len%2==1)cout<<"First"<<endl;
        else cout<<"Second"<<endl;
    }
    return 0;
}