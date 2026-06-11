#include<iostream>
using namespace std;

bool check(string t,char c){
    for(int i=0;i<t.length();i++){
        if(t[i]!=c) return false;
    }
    return true;
}

int main(){
    string s; cin>>s;
    int ans=1e9;
    for(char c='a';c<='z';c++){
        string t=s;
        for(int i=0;;i++){
            if(t.length()==0) break;
            if(check(t,c)){
                ans=min(ans,i);
                break;
            }
            string nt;
            for(int j=0;j<t.length()-1;j++){
                if(t[j]==c||t[j+1]==c) nt+=c;
                else nt+=t[j];  
            }
            t=nt;
        }
    }
    cout<<ans<<endl;
}