#include<iostream>
using namespace std;
int main(){
    string s;
    cin>>s;
    string result="";
    for(int i=0;i<s.length();i++)
    {
        if(i==5||i==13){
            result+=" ";
            continue;
        }
        result+=s[i];
    }
    cout<<result;
}