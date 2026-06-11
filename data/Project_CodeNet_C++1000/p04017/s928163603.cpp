#include<bits/stdc++.h>
using namespace std;
using ll = long long;
int pre[20][100002];


ll cal(int a, int b){
    ll days = 0;
    while(true){
        if(a == b) return days;

        int k = 0;
        while(pre[k][a]<b) k++;

        if(k==0) return days+1LL;
        else {
            a = pre[k-1][a];
            days+=(1LL << (k-1));
        }
    }
}


int main(){
    int n,l,q;
    cin>>n;
    vector<pair<int,int>> arr;
    vector<int> mp(n+1);
    vector<int> x(n);
    for(int i = 0; i < n; i++){
        int t;cin>>t;
        x[i] = t;
        arr.push_back({t,i});
        mp[i] = t;
    }

    sort(arr.begin(),arr.end());
    sort(x.begin(),x.end());
    cin>>l>>q;

    for(int i = 0; i < n; i++){
        pre[0][i] = upper_bound(x.begin(),x.end(),x[i]+l) - x.begin();
        pre[0][i]-=1;
    }

    int k = 0;
    while(n>>k > 0) k++;

    for(int i = 0 ; i < k; i++){
        for(int j = 0; j < n; j++){
            pre[i+1][j] = pre[i][pre[i][j]];
        }
    }

    while(q--){
        int a,b;cin>>a>>b;
        int ai,bi;
        a--;b--;
        ai = mp[a],bi = mp[b];
        if(ai>bi) swap(ai,bi);
        
        a = lower_bound(x.begin(),x.end(),ai) - x.begin();
        b = lower_bound(x.begin(),x.end(),bi) - x.begin();
        
        ll days = cal(a,b);
        cout<<days<<endl;;

    }
    

}
