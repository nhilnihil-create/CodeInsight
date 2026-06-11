//g++  7.4.0

#include<bits/stdc++.h>
using namespace std;
int main()
{
   string s;int flag=0;
   cin>>s;
    int a[26]={0};
    for(int i=0;i<s.length();i++){
        int k=(int)s[i];
        a[k-97]++;
    }
    for(int i=0;i<26;i++){
        if(a[i]==0){
            cout<<(char)(i+97);
            flag = 1;
            break;
        }
    }
    if(flag==0){
        cout<<"None";
    }
}