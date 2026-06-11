#include<iostream>
#include<vector>
#include<string>
#include<map>
#include<algorithm>
using namespace std;

int main(){
    string s;
    cin>>s;
    bool nflag=false,sflag=false,eflag=false,wflag=false;
    for(int i=0;i<s.size();i++){
        if(s[i]=='N')nflag=true;
        else if(s[i]=='W')wflag=true;
        else if(s[i]=='S')sflag=true;
        else if(s[i]=='E')eflag=true;
    }
    if(sflag==nflag&&wflag==eflag)cout<<"Yes"<<endl;
    else cout<<"No"<<endl;
    return 0;
}