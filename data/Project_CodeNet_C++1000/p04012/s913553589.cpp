#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
int main(){
    string s;
    cin>>s;
    vector<int>alpha(26,0);
    for(int i=0;i<s.length();i++)
    {
        if(s[i]>='a'&&s[i]<='z'){
            alpha[s[i]-'a']++;
        }
    }
    bool no=false;
    for(int i=0;i<alpha.size();i++)
    {
        if(alpha[i]%2!=0){
            no=1;
        }
    }
    if(no){
        cout<<"No"<<endl;
    }
    else{
        cout<<"Yes"<<endl;
    }
}