#include<iostream>
#include<string>

using namespace std;
int main(){
    string s;
    cin>>s;
    cout<<s[0]<<int(s.length())-2<<s[int(s.length())-1];
}