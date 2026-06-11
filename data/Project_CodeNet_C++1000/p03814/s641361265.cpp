#include<iostream>
using namespace std;
int main(){
    string s;
    cin>>s;
    int start=-1,end;
    for(int i=0;i<s.length();i++)
    {
        if(s[i]=='A'&&start==-1){
            start=i;
        }
        if(s[i]=='Z'&&start!=-1){
            end=i;
        }
    }
    cout<<end-start+1;
}