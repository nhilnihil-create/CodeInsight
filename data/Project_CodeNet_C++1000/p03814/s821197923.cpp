#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<ll,ll> P;
int main(void){
    string s; cin>>s;
    int a,z;
    for(int i=0;i<s.size();i++){
        if(s[i]=='Z') z=i;
    }
    for(int i=s.size()-1;i>=0;i--){
        if(s[i]=='A') a=i;
    }
    cout<<z-a+1<<endl;
    
}
