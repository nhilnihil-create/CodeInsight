#include <iostream>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
#include <map>
using namespace std;
char y[1000000],temp[1000000]; 
int main(){
map<char,char> a;
a['b']='d';a['p']='q';
a['q']='p';a['d']='b';
cin>>y;
int m=strlen(y);
strcpy(temp,y);
for(int i=0;i<m/2;i++)swap(y[i],y[m-i-1]);
for(int i=0;i<m;i++)y[i]=a[y[i]];
if(strcmp(y,temp)==0)cout<<"Yes";
else cout<<"No";
return 0;
}
