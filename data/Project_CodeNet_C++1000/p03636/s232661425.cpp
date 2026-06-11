#include<bits/stdc++.h>
using namespace std;
int main(){
    char s[100];
    int len=0;
    cin>>s;
    while(s[len]){
        len++;
    };
    cout<<s[0]<<len-2<<s[len-1];
    return 0;
}