#include<iostream>
using namespace std;

#define ll long long
int main(){

string s;

cin>>s;

string ans;

for(char c: s){
    if(c=='0')
    ans+='0';
    if(c=='1')
    ans+='1';
    if(c=='B'){
        if(!ans.empty())
        ans.pop_back();       
    }
    
}
cout<<ans;
  
}