#include <bits/stdc++.h>
using namespace std;

int main() {
    string s;
    cin>>s;
    //key was not to look for the whole string but just look for any three character as
    //it would also accomplish the task we were trying to figure out
    if(s.length()==2){
        if(s[0]==s[1])cout<<1<<" "<<2<<endl;
        else cout<<-1<<" "<<-1<<endl;
    }else{
        for(int i=0;i<s.length()-2;i++){
            if(s[i]==s[i+1] || s[i+1]==s[i+2] || s[i+2]==s[i]){
                cout<<i+1<<" "<<i+3<<endl;
                return 0;
            }    
        }
        
        cout<<-1<<" "<<-1<<endl;
        return 0;
    }
}