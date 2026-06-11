#include<iostream>
using namespace std;
int main(){
    string s1,s2,s3;
    cin>>s1>>s2>>s3;
    cout<<char(s1[0]-'a'+'A');
    cout<<char(s2[0]-'a'+'A');
    cout<<char(s3[0]-'a'+'A');
}