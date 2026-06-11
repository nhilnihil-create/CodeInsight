#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
string s;
bool x[30];
int main(void){
    cin>>s;
    for(int i=0;i<s.size();i++){
        x[s[i]-'a']=true;
    }
    for(int i=0;i<26;i++){
        if(x[i]==false){
            char ans='a'+i;
            cout<<ans<<endl;
            return 0;
        }
    }
    cout<<"None"<<endl;
    
}
