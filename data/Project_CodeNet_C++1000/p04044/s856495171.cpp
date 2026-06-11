#include <bits/stdc++.h>
#define f(i,j,k) for(int i=j;i<k;i++)
using namespace std;
int main(){
    long long n,l;
    cin>>n>>l;
    string ans="";
    string s[n];
    f(i,0,n){
        cin>>s[i];
    }
    sort(s,s+n);
    f(i,0,n){
        ans+=s[i];
    }
    cout<<ans<<endl;
    return 0;
}
