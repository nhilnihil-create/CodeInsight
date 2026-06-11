#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int x,y,ans;
char s[100001];
string a,b;
int main(){
    cin>>a,b=a;
    reverse(a.begin(),a.end());
    for(int i=0;i<a.size();i++){
		if(a[i]=='d') a[i]='b';
		else if(a[i]=='q') a[i]='p';
        else if(a[i]=='b') a[i]='d';
        else if(a[i]=='p') a[i]='q';
    }
    if(a==b) printf("Yes");
    else printf("No");
    printf("\n");
    return 0;
}