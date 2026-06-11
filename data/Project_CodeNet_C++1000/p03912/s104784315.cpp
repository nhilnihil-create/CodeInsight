#include <bits/stdc++.h>
using namespace std;
const long long mod = 1000000007;

int main(){
    int n,m;
    cin >> n >> m;
    int x[n];
    for(int i=0; i<n; i++) cin >> x[i];
    int cnt[100001];
    fill(cnt,cnt+100001,0);
    vector<int> a[m],b[m];
    for(int i=0; i<n; i++){
        cnt[x[i]]++;
    }
    for(int i=0; i<100001; i++){
        if(cnt[i]%2==0){
            for(int j=0; j<cnt[i]; j++){
                b[i%m].push_back(i);
            }
        }
        else{
            a[i%m].push_back(i);
            for(int j=1; j<cnt[i]; j++){
                b[i%m].push_back(i);
            }
        }
    }
    int ans = 0;
    ans += (a[0].size()+b[0].size())/2;
    if(m%2==0) ans += (a[m/2].size()+b[m/2].size())/2;
    for(int i=1; i<m/2+1; i++){
        int p=i,q=m-i;
        if(p==q) break;
        if(a[p].size()+b[p].size() < a[q].size()+b[q].size()) swap(p,q);
        int ap=a[p].size(),bp=b[p].size(),aq=a[q].size(),bq=b[q].size();
        ans += aq+bq;
        if(ap > aq+bq) ans += bp/2;
        else ans += (ap+bp-aq-bq)/2;
    }
    cout << ans << endl;
    return 0;
}
