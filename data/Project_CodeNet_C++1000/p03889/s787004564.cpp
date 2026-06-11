#include<bits/stdc++.h>
#define mem(i,j) memset(i,j,sizeof(i))
#define Endl printf("\n")
#define ka printf(" ")
using namespace std;

const int N=1e5+5;
int main(){
    char t[N],s[N];
    cin>>t;
    int len=strlen(t),k=len-1;
    for(register int i=0;i<len;i++)s[k--]=t[i];
    for(register int i=0;i<len;i++){
        if(s[i]=='b')s[i]='d';
        else if(s[i]=='d')s[i]='b';
        else if(s[i]=='p')s[i]='q';
        else s[i]='p';
    }
    for(register int i=0;i<len;i++){
        if(s[i]!=t[i]){cout<<"No"<<endl;return 0;}
    }
    cout<<"Yes"<<endl;
    return 0; 
}