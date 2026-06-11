#include<iostream>
using namespace std;
int main(){
    string s;
    cin>>s;
    for(int i=0;i<s.size()-1;i++)if(s[i]==s[i+1]||s[i]==s[i+2])
    {cout<<i+1<<" "<<i+2+(s[i]!=s[i+1])<<endl;return 0;}
    cout<<-1<<" "<<-1<<endl;
    return 0;
}