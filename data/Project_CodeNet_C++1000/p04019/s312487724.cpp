#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
string s;
bool x[5];
int main(void){
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]=='N'){
            x[0]=true;
        }else if(s[i]=='S'){
            x[1]=true;
        }else if(s[i]=='W'){
            x[2]=true;
        }else{
            x[3]=true;
        }
    }
    if(x[0]==x[1]&&x[2]==x[3]){
        cout<<"Yes"<<endl;
    }else{
        cout<<"No"<<endl;
    }

}

