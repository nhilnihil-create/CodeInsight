#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
int main(){
    long n,k,max=0,ans=1e11;
    cin >> n >> k;
    vector<int> a(n),b(n);//b:i番もふくめ左側のmaxhの場所
    rep(i,n) cin >> a[i];
    rep(i,n){
        if(max<a[i]) max = a[i];
        b[i] = max;
    }
    for(int i=0;i<(1<<n);i++){
        long cost=0,cnt=0;
        bitset<15> s(i);
        vector<int> cand,c=a,d=b;//使う建物の番号,maxh情報の初期化
        for(int j=0;j<n;j++){
            if(s.test(j)) cand.push_back(j);
        }
        for(auto j:cand){
            cost += (d[j]-c[j])+1;//c[j]をd[j]+1に差し替える
            c[j] = d[j]+1;
            int k=j+1;
            while(c[k]<d[j]+1&&k<n){
                d[k] = d[j]+1;
                k++;
            }
        }
        int max1 = 0;
        rep(j,n){
            if(max1<c[j]){
                max1 = c[j];
                cnt++;
            }
        }
        if(k <= cnt) ans = min(cost,ans);
    }
    cout << ans << endl;
}