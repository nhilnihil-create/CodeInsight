#include<bits/stdc++.h>
using namespace std;
#define MAXN 100000
typedef long long ll;
string tobin(int x){return !x?"":tobin(x/2)+(char)(x%2+'0');}
int main(){
    ll sum=0;
    string s;cin>>s;
    for(int i=0;i<(1<<(s.size()-1));++i){
        ll tmp=0;
        for(int j=0;j<s.size();++j){
            tmp=tmp*10+s[j]-'0';
            if((i>>j)&1){/*cout<<tmp<<endl*/;sum+=tmp;tmp=0;}
        }
        sum+=tmp;
        // cout<<tmp<<endl;
    }
    cout<<sum<<endl;
    return 0;
}
