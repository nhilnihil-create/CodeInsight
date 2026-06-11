#include<bits/stdc++.h>
using namespace std;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    long a,b,t,s=0;
    cin>>t;
    while(t--){
        cin>>a>>b;
        s=s+(b-a)+1;
    }
    cout<<s;
    return 0;
}
  