#include<bits/stdc++.h>
using namespace std;   
int main(){
    int n;
    string s,t;
    cin>>n>>s>>t;
    for(int i=0;i<n;i++){
        int c=1;
        for(int j=0;j<n-i;j++){
            if(s[i+j]!=t[j]){
                c=0;
                break;
            }
        }
        if(c==1){
            cout<<n+i<<endl;
            return(0);
        }
    } 
    cout<<n*2<<endl;
    return 0;
}