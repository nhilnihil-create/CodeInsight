#include <bits/stdc++.h>
using namespace std;
struct point{double x;double y;};
int i,j,k,count1=0,count2=0;

int main(void){
    string str;
    cin>>str;
    int n=0,w=0,s=0,e=0,ans=0;
    for(i=0;i<str.length();i++){
        if(str[i]=='N')n++;
        if(str[i]=='W')w++;
        if(str[i]=='S')s++;
        if(str[i]=='E')e++;
    }
    if(n>=1&&s>=1&&w==0&&e==0)ans=1;
    if(n>=1&&s>=1&&w>=1&&e>=1)ans=1;
    if(n==0&&s==0&&w>=1&&e>=1)ans=1;
    cout<<(ans? "Yes":"No")<<endl;
}