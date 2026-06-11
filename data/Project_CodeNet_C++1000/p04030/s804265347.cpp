#include <bits/stdc++.h>
using namespace std;
int main(void){
    // Your code here!
    string s;cin>>s;
    string ans;
    for(int i=0;i<s.size();i++){
        if(s[i]=='B'){
            if(ans.size()==0){
                continue;
            }
            ans=ans.erase(ans.size()-1);
        }
        else{
            ans+=s[i];
        }
    }
    cout<<ans<<endl;
    return 0;
}
