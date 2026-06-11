#include<iostream>
#include<vector>
using namespace std;
int main(){
    string s;
    cin>>s;
    vector<bool>dp(26,false);
    for(int i=0;i<s.size();i++)
    {
        dp[s[i]-'a']=true;
    }
    int index=-1;
    for(int i=0;i<26;i++)
    {
        if(!dp[i]){
            index=i;
            break;
        }
    }
    if(index!=-1){cout<<char(index+'a');}
    else
    {
        cout<<"None"<<endl;
    }
    
}