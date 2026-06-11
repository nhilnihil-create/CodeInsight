#include <iostream>
#include<bits/stdc++.h>
using namespace std;

int main()
{
    char s[200002];
    int i,j,a,b;
    cin>>s;
    int n=strlen(s);
    for(i=0;i<n;i++){
        if(s[i]=='A'){
            a=i;
            break;
        }
    }
    for(j=n-1;j>=0;j--){
        if(s[j]=='Z'){
            b=j;
            break;
        }
    }
    cout<<b-a+1;
    return 0;
}
