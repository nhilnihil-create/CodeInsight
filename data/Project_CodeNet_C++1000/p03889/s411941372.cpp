#include <bits/stdc++.h>  
using namespace std; 
int main(){
    char a[100005],b[100005];
    cin>>a;
    int a1=strlen(a),ans=0;
    for(int i=0;i<a1;i++){
        if(a[i]=='b') b[i]='d';
        if(a[i]=='d') b[i]='b';
        if(a[i]=='q') b[i]='p';
        if(a[i]=='p') b[i]='q';
    }
    for(int i=0;i<a1;i++){
        if(a[i]!=b[a1-i-1]){
            cout<<"No";
            return 0;
        }
    }
    cout<<"Yes";
    return 0;
}