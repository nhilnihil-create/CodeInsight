#include<bits/stdc++.h>
using namespace std;

int main(){
    long long N; cin >> N;
    long long a[N];
    for(int i=0;i<N;i++) cin >> a[i];
    vector<pair<long long,long long>> res;
    for(long long i=0;i<N;i++){
        res.push_back({a[i],i+1});
    }
    sort(res.begin(),res.end());
    long long ans=0;
    set<long long> st;
    st.insert(0);
    st.insert(N+1);
    for(int i=0;i<N;i++){
        st.insert(res[i].second);
        auto tmp=st.upper_bound(res[i].second);
        long long r=*tmp;
        auto tmp2=st.lower_bound(res[i].second);
        long long l=*(--tmp2);
        //cout << l << " " << r << endl;
        ans+=res[i].first*(r-res[i].second)*(res[i].second-l);
    }
    cout << ans << endl;
}