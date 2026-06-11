#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
int main(void){
    string s,t; cin>>s>>t;
    if(s==t){
        cout<<"EQUAL"<<endl;
        return 0;
    }else{
        if(s.size()<t.size()){
            cout<<"LESS"<<endl;
            return 0;
        }else if(s.size()>t.size()){
            cout<<"GREATER"<<endl;
            return 0;
        }else{
            for(int i=0;i<s.size();i++){
                if(s[i]-'0'<t[i]-'0'){
                    cout<<"LESS"<<endl;
                    return 0;
                }
                if(s[i]-'0'>t[i]-'0'){
                    cout<<"GREATER"<<endl;
                    return 0;
                }
            }
        }
    }
    
}
