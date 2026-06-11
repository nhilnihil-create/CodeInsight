#include<bits/stdc++.h>
#define REP(i,n) for(int i=0,i##_len=(n);i<i##_len;++i)
#define rep(i,a,b) for(int i=int(a);i<int(b);++i)
#define All(x) (x).begin(),(x).end()
using namespace std;
using ll = long long;

int main(){
    string s;cin>>s;
    int K;cin>>K;
    REP(i,s.size()){
        if(s[i]!='a'&&K>='z'-s[i]+1){
            K-='z'-s[i]+1;
            s[i]='a';
        }
        if(i+1==s.size()){
            s[i]=(s[i]-'a'+K%26)%26+'a';
        }
    }
    cout<<s<<endl;
}
