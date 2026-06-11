#include<iostream>
using namespace std;

int main(){
    string s;
    cin>>s;
    int n=s.size(),ans=0;
    for(int i=0;i<n-1;i++){
        if(s[i]!=s[i+1]) ans++;
    }
    cout<<ans<<endl;
}