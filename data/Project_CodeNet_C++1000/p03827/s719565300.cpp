#include <bits/stdc++.h>
using namespace std;
int main(){
    string s;
    long long n,x=0,max=0;
    cin>>n;
    cin>>s;
    for(int i=0;i<n;i++){
        if(s[i]=='I'){
            x+=1;
        }
        else{
            x-=1;
        }
        if(max<x){
            max=x;
        }
    }
    cout<<max<<endl;
    return 0;
}
