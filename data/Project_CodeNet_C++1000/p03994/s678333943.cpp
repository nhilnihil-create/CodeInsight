#include <bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=int(a);i<int(b);i++)
typedef long long ll;


int main(){
    ll K;
    string s;cin>>s>>K;
    rep(i,0,s.size()){
        if(s.at(i)!='a'&&'{'-s.at(i)<=K){
            K=K-('{'-s.at(i));
            s.at(i)='a';
        }
    }
    if(K!=0){
    K=K%26;
    s.at(s.size()-1)=(s.at(s.size()-1)-'a'+K)%26+'a';
    }
    cout<<s<<endl;
    
}





