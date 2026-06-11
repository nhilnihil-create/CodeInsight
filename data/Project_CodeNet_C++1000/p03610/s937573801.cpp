#include<iostream>
#include<string>
using namespace std;

int main(){
    string s,ans;
    cin>>s;

    for(int i=0;i<s.size();i+=2){
        ans+=s[i];
    }
cout<<ans;


}
