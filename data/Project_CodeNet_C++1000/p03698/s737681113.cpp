#include<iostream>
#include<vector>
using namespace std;
int main(){
    string s;
    vector<bool>v(26,false);
    cin>>s;
    bool no=false;
    for(int i=0;i<s.length();i++)
    {
        if(!v[s[i]-'a']){
            v[s[i]-'a']=true;
        }
        else{
            no=true;
            break;
        }
    }
    if(!no){
        cout<<"yes"<<endl;
    }
    else{
        cout<<"no"<<endl;
    }
}