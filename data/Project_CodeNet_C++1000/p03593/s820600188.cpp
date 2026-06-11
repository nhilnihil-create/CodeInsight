#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
int main(){
    cin.tie(NULL); cout.tie(NULL);
    ios_base:: sync_with_stdio(false);
    ll h,w;cin>>h>>w;
    vector<ll> cnt(26,0) , req(5,0);
    for(ll i=0;i<h*w;i++){
        char ch;cin>>ch;
        cnt[ch-'a']++;
    }

    for(ll i=0;i<=h-i-1;i++){
        for(ll j=0;j<=w-j-1;j++){
            ll tot=1;
            if(i<h-i-1)tot*=2;
            if(j<w-j-1)tot*=2;
            req[tot]++;
        }
    }

    for(ll i=0;i<26;i++){
        while(req[4]>0 && cnt[i]>=4)req[4]--,cnt[i]-=4;
        while(req[2]>0 && cnt[i]>=2)req[2]--,cnt[i]-=2;
        if(cnt[i]>req[1])return cout<<"No" , 0;
        req[1]-=cnt[i];
    }
    cout<<"Yes";

}



