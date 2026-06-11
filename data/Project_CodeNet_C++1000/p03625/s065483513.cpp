#include <bits/stdc++.h>
using namespace std;
using Graph = vector<vector<int>>;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define pii pair<int,int>
const long long MOD=1000000007;

int main(){
    int n;
    cin>>n;
    map<int,int> bou;
    rep(i,n){
        int a;
        cin>>a;
        bou[-1*a]++;//大きい順に取り出すため
    }
    long long ans=1;
    int count=0;
    for(auto a:bou){
        int l=-1*a.first,k=a.second;
        while(k>=2 && count<2){
            ans*=l;
            k-=2;
            count++;
        }
        if(count==2) break;
    }
    if(count==2) cout<<ans<<endl;
    else cout<<"0"<<endl;
    return 0;
}
