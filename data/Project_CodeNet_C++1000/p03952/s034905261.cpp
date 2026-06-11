#include <bits/stdc++.h>
using namespace std;
#define int long long
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rrep(i,n) for(int (i)=((n)-1);(i)>=0;(i)--)
#define itn int
#define all(x) (x).begin(),(x).end()
#define F first
#define S second
const long long INF = 1LL << 60;
const int MOD = 1000000007;
signed main(void){
    int n,x; cin>>n>>x;
    int ma = 2*n-1;
    int mid = ma/2 +1;
    //cout<<mid<<endl;
    if(x==1|| x==ma) {cout<<"No"<<endl; return 0;}
    vector <int> a(2*n-1, 114514); 
    a[mid-1] = x;
    a[mid-2] = 1, a[mid] = ma;
    priority_queue <int> pq;
    for(int i=2;i<ma;i++){
        if(i==x) continue;
        pq.push(i);
        //cout<<i<<endl;
    }
    int l=0;
    while(a[l]==114514){
        int tmp = pq.top(); pq.pop();
        a[l++] = tmp;
    }
    int r = ma-1;
    while(a[++mid] == 114514){
        if(mid>=ma) break;
        a[mid] = pq.top(); pq.pop();
    }
    cout<<"Yes"<<endl;
    rep(i,ma) cout<<a[i]<<endl;
}
