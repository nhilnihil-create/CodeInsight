#include<bits/stdc++.h>
using namespace std;

int n,k;
long long a[200005],ans;
map<long long,int> mp;
int bit[200005];

int sum(int pos){
    int res=0;
    while(pos>0){
        res+=bit[pos];
        pos-=pos&-pos;
    }
    return res;
}

void add(int pos,int val){
    while(pos<=n+1){
        bit[pos]+=val;
        pos+=pos&-pos;
    }
}

int main(){

    ios::sync_with_stdio(false);
    cin.tie(0);
    cout.tie(0);

    cin>>n>>k;
    for(int i=1;i<=n;i++){
        cin>>a[i];
        a[i]=a[i]-k+a[i-1];
        mp[a[i]]=0;
    }
    mp[0]=0;
    int cnt=0;
    for(map<long long,int>::iterator it=mp.begin();it!=mp.end();it++){
        it->second=++cnt;
    }
    add(mp[0],1);
    for(int i=1;i<=n;i++){
        ans+=sum(mp[a[i]]);
        add(mp[a[i]],1);
    }
    cout<<ans<<endl;

    return 0;
}