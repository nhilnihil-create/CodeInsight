#include <bits/stdc++.h>
#define rep(i,n) for(int i = 0;i<n;i++)
using namespace std;
int main(){
    int n;
    cin >> n;
    long long a[n];
    rep(i,n) cin >> a[i];
    set<long long> st;
    map<long long,int> mp,mp2; 
    rep(i,n){
        st.insert(-a[i]);
        mp2[a[i]]++;
        if(mp.find(a[i])==mp.end()) mp[a[i]]=i;
    }
    st.insert(0);
    mp2[0]=1;
    mp[0]=-1;
    long long now = -*st.begin();
    long long now_itr = mp[now];
    long long ans[n];
    long long cnt = mp2[now];
    //cout << now << " " << now_itr << " "<< cnt << endl;
    fill_n(ans,n,0);
    for(auto itr = st.begin();itr!=st.end();itr++){
        if(itr==st.begin()) itr++;
        long long next = *itr;
        next*=(-1);
        long long next_itr = mp[next];
        ans[now_itr]+=(cnt)*(now-next);
        cnt+=(mp2[next]);
        now = next;
        if(now_itr>next_itr){
            now_itr=next_itr;
        }
        //cout << next << " " << next_itr << endl;
    }
    rep(i,n) cout << ans[i] << endl;
}