#include<bits/stdc++.h>
#define _GLIBCXX_DEBUG
#define rep(i,n) for(int i=0;i< (n);i++)
#define rep1(i,n) for(int i=1;i<= (n);i++)
using namespace std;
typedef long long ll;
typedef pair<int,int> P;

const static ll MOD = (1e+9)+7;

int main(){
    int k,t;cin>>k>>t;
    vector<int> lst(t);
    rep(i,t)cin>>lst[i];
    int ans = -1;
    while(lst[0] != 0){
        sort(lst.begin(),lst.end(),greater<int>());
        lst[0]--;
        if(t > 1 && lst[1] != 0){
            lst[1]--;
        }else{
            ans++;
        }
    }
    cout<<max(ans,0)<<endl;
    return 0;
}