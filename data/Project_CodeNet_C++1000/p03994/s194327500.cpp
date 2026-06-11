#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> P;
const ll MOD=1000000007;
char c[100005];
int main(void){
    string s;
    cin>>s;
    ll k;
    cin>>k;
    ll ans=0;
    ll n=s.size();
    for(int i=0;i<n;i++){
        c[i]=s[i];
    }
    for(int i=0;i<n;i++){
        if(c[i]!='a'&&'z'-c[i]+1<=k){
            k-=('z'-c[i]+1);
            c[i]='a';
        }
        //cout<<c[i]<<" "<<k<<endl;
    }
    //cout<<k<<endl;
    k=k%26;
    if(k>0){
        int t=c[n-1]-'a'+k;
        //cout<<t<<endl;
        if(t>26){
            t-=26;
        }
        c[n-1]=t+'a';
    }
    for(int i=0;i<n;i++){
        cout<<c[i];
    }
    cout<<endl;
    
}
