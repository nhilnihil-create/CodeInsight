#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
bool x[30];
int main(void){
    string s; cin>>s;
    for(int i=0;i<s.size();i++){
        if(x[s[i]-'a']){
            cout<<"no"<<endl;
            return 0;
        }else{
            x[s[i]-'a']=true;
        }
    }
    cout<<"yes"<<endl;
    
}
