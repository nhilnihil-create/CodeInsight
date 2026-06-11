#include<bits/stdc++.h>
using namespace std;


int main(){
    string s;
    cin>>s;
    int n=s.size();
    if(n%2==0){
        if(s[0]==s[n-1]){
            cout<<"First"<<endl;
            return 0;
        }
        else{
            cout<<"Second"<<endl;
            return 0;
        }
    }
    else {
        if(s[n-1]==s[0]){
            cout<<"Second"<<endl;
            return 0;
        }
        else {
            cout<<"First"<<endl;
            return 0;
        }
    }

}