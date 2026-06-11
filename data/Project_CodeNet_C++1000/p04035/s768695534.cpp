#include<iostream>
#include<vector>
#include<algorithm>
#include<string>
#include<queue>

using namespace std;
#define int long long
#define rep(i,n) for(int i=0;i<n;++i)
#define rep1(i,n) for(int i=1;i<=n;++i)

signed main(){
    int n,l;cin>>n>>l;
    vector<int> a(n);
    rep(i,n)cin>>a[i];
    bool flag=false;
    int two=a[0];
    int index=0;
    rep1(i,n-1){
        two=a[i]+a[i-1];
        if(two>=l){
            index=i;
            flag=true;
            break;
        }
    }
    vector<int> res;
    rep1(i,index-1){
        res.push_back(i);
    }
    for(int i=n-1;i>=index;i--){
        res.push_back(i);
    }
    if(!flag){
        cout<<"Impossible"<<endl;
    }
    else{
        cout<<"Possible"<<endl;
        rep(i,res.size()){
            cout<<res[i]<<endl;
        }
    }
    //cout<<cnt<<endl;
    return 0;
}