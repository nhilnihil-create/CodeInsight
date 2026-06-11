#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

int main(){
    string s,ans;
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]=='0')ans=ans+'0';
        else if(s[i]=='1')ans=ans+'1';
        else if(s[i]=='B'){
            if(ans.length()==0)continue;
            else ans=ans.substr(0,ans.length()-1);
        }
    }
    cout<<ans<<endl;
    return 0;
}