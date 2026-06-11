#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

ll n,dpf[300001],dpl[300001],ans=-1e18;
vector<ll> a(300001);
vector<ll> vf,vl;
map<ll,ll> mpf,mpl;

int main(){
    cin >> n;
    for(int i = 0;i < 3*n;i ++){
        cin >> a[i];
        if(i<n) mpf[a[i]] ++,dpf[n-1]+=a[i];
        if(i>2*n-1) mpl[a[i]] ++,dpl[2*n]+=a[i];
    }

    for(int i = n;i < 2*n;i ++){
        if(a[i]>mpf.begin()->first){
            dpf[i] = dpf[i-1]+a[i]-mpf.begin()->first;
            mpf.begin()->second --;
            if(!mpf.begin()->second) mpf.erase(mpf.begin());
            mpf[a[i]] ++;
        }else{
            dpf[i] = dpf[i-1];
        }
    }
    for (int i = 2*n-1;i >= n;i --){
        if(a[i]<mpl.rbegin()->first){
            dpl[i] = dpl[i+1]+a[i]-mpl.rbegin()->first;
            mpl.rbegin()->second --;
            if(!mpl.rbegin()->second) mpl.erase(mpl.rbegin()->first);
            mpl[a[i]] ++;
        }else{
            dpl[i] = dpl[i+1];
        }
    }
    for(int i = n-1;i < 2*n;i ++){
        ans = max(ans,dpf[i]-dpl[i+1]);
    }
    cout << ans << endl;
    return 0;
}