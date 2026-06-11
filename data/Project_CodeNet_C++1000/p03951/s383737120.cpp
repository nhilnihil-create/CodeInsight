#include<iostream>
using namespace std;

int main(){
    int n;
    string s,t;
    cin>>n>>s>>t;
    int ans=0;
    for(int i=0;i<n;i++){
        int cnt=0;
        for(int j=0;j<n-i;j++){
            if(s[i+j]!=t[j]) break;
            cnt++; 
        }
        ans=max(ans,cnt);
    }
    cout<<n*2-ans<<endl;
}