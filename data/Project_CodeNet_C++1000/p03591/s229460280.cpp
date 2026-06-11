#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
int main(void){
    string s; cin>>s;
    if(s.size()<4){
        cout<<"No"<<endl;
    }else{
        if(s[0]=='Y'&&s[1]=='A'&&s[2]=='K'&&s[3]=='I'){
            cout<<"Yes"<<endl;
        }else{
            cout<<"No"<<endl;
        }
    }
    
}
