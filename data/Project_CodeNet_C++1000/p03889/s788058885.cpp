#include<cmath>
#include<cctype>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define ll long long
using namespace std;
char a[100001],b[100001];
int lena;
int main(){
    cin>>a;
    lena=strlen(a); 
    for(register int i=0;i<lena;i++)
    {
        if(a[i]=='b') b[lena-i-1]='d';
        else if(a[i]=='d') b[lena-i-1]='b';
        else if(a[i]=='p') b[lena-i-1]='q';
        else if(a[i]=='q') b[lena-i-1]='p';
    }
    if(!strcmp(a,b)) cout<<"Yes";
    else cout<<"No";
    return 0;
}