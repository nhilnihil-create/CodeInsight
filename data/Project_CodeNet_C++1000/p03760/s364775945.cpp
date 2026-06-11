#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
int main(void){
    string s,t;
    cin>>s>>t;
    if(s.size()==t.size()){
        for(int i=0;i<s.size();i++){
            cout<<s[i]<<t[i];
        }
    }else{
        for(int i=0;i<t.size();i++){
            cout<<s[i]<<t[i];
        }
        cout<<s[s.size()-1];
    }
    cout<<endl;
    
}
