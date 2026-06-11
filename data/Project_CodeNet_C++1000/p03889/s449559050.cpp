#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
char to[299];
int main(){
	to['b']='d';
	to['d']='b';
	to['p']='q';
	to['q']='p';
    string a,b;
    cin>>a;
    b=a;
    reverse(a.begin(),a.end());
    for(int i=0;i<a.length();i++)a[i]=to[a[i]];
    if(a==b) cout<<"Yes";
    else cout<<"No";
}