#include<cstdio>
#include<iostream>
#include<cstring>
#include<string>
using namespace std;
char s[100001],s2[100010],s3[100001];
int flag=1,len,L,R;
int main(){
    cin>>s;
    len=strlen(s);
    for(int i=len-1;i>=0;i--){
        L=i,R=len-i-1;
        if(s[L]==s[R])
        flag=0;
        else {
            flag=1;
            break;
        }
    }
    if(!flag){
        cout<<"Yes"<<endl;
        return 0;
    }
    int cnt=0;
    for(int i=0;i<len;i++){
        s2[len-i-1]=s[i];
        if(s2[len-i-1]=='b')
        s2[len-i-1]='d';
        else if(s2[len-i-1]=='d')
        s2[len-i-1]='b';
        else if(s2[len-i-1]=='p')
        s2[len-i-1]='q';
        else if(s2[len-i-1]=='q')
        s2[len-i-1]='p';
        if(s2[len-i-1]==s[len-i-1])
         cnt=1;
         else
         {
         	cnt=0;
         	break;
		 }
    }
    if(cnt==1){
        cout<<"Yes"<<endl;
        return 0;
    }
    cout<<"No"<<endl;
    return 0;
}