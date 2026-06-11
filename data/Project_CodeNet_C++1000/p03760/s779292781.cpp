#include <bits/stdc++.h>
using namespace std;
int main(){
    string o,e,ans;
    cin>>o>>e;
    ans="";
    for(int i=0;i<o.length();i++){
        ans+=o[i];
        if(o.length()!=e.length() && i+1==o.length()) break;
        ans+=e[i];
    }
    cout<<ans<<endl;
    return 0;
}