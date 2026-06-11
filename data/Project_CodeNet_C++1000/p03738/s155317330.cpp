#include <bits/stdc++.h>
#define pi 3.14159
using namespace std;
typedef long long LL;
const LL MOD = 1e9 + 7;
const int N = 1e5 + 7, M = 1e7, OO = 0x3f3f3f3f;
#define AC ios::sync_with_stdio(0);cin.tie(0);cout.tie(0); cin.sync_with_stdio(0);
int main()
{
int n,m,i,flag=0;
string s1,s2;
cin>>s1>>s2;
n=s1.size();
m=s2.size();
if(n>m){
    printf("GREATER");
}
else if(n<m){
    printf("LESS");
}
else{
    for(i=0;i<n;++i){
        if(s1[i]>s2[i]){
            flag=1;
            break;
        }
        else if(s1[i]<s2[i]){
            flag=2;
            break;
        }
    }
    if(flag==0){
        printf("EQUAL");
    }
    else if(flag==1){
        printf("GREATER");
    }
    else{
        printf("LESS");
    }
}




    return 0;
}
