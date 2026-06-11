#include "bits/stdc++.h"
#define rep(i,n) for (int i=0; i<(n); ++i)
using namespace std;
using ll =long long;
using P =pair<int,int>;

int main(){
    ll n;
    cin >> n;
    vector <ll> a(n-1),b(n-1),c(n-1);
    vector <vector <ll>> m(n+1),m2(n+1);
    rep(i,n-1){
        cin >> a[i] >> b[i] >> c[i];
        m[a[i]].push_back(b[i]);
        m[b[i]].push_back(a[i]);
        m2[a[i]].push_back(c[i]);
        m2[b[i]].push_back(c[i]);   
    }

    ll qqq,k;
    cin >> qqq >> k;
    vector <ll> x(qqq),y(qqq);
    rep(i,qqq){
        cin >> x[i] >> y[i];
    }
    vector <ll> kyo(n+1);
    vector <int> ans(n+1,0);
    queue <ll> q;
    q.push(k);
    ll qq,l;
    kyo[k]=0;
    while(q.size()!=0){
        
        qq=q.front();
        //cout << qq << endl;
        q.pop();
        l=m[qq].size();
        //cout << l << endl;
        ans[qq]=1;
        rep(i,l){
            if(ans[m[qq][i]]==0){
                //cout << m[qq][i] << endl;
                ans[m[qq][i]]=1;
                //cout <<  kyo[qq] << endl;
                //cout << m2[qq][i] << endl;
                kyo[m[qq][i]]=kyo[qq]+m2[qq][i];
               // cout << "t" << endl;
                q.push(m[qq][i]);
                //cout << "t" << endl;
            }
        }
    }

    rep(i,qqq){
        cout << kyo[x[i]]+kyo[y[i]] << endl;
    }

    

    return 0;
}