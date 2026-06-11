#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define rep(i,n) for(int i=0;i<n;i++)


int main(){
    string s,t;
    cin>>s;cin>>t;
    if(s.size()<t.size()) cout<<"LESS"<<endl;
    else if(s.size()>t.size()) cout<<"GREATER"<<endl;
    else{
        rep(i,(int)s.size()){
            if(s[i]>t[i]){
                cout<<"GREATER"<<endl;
                return 0;
            }else if(s[i]<t[i]){
                cout<<"LESS"<<endl;
                return 0;
            }
        }
        cout<<"EQUAL"<<endl;
        return 0;
    }
}