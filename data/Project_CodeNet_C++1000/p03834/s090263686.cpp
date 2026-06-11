#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
string s;
int main(void){
    cin>>s;
    for(int i=0;i<s.size();i++){
        if(s[i]!=','){
            cout<<s[i];
        }else{
            cout<<" ";
        }
    }
    cout<<endl;
    
}
