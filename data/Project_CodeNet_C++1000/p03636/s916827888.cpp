#include<bits/stdc++.h>
using namespace std;
int main(){
    char a[101];
    int len=0;
    cin>>a;
    while(a[len]){
        len++;
    };
    cout<<a[0]<<len-2<<a[len-1];
    return 0;
}