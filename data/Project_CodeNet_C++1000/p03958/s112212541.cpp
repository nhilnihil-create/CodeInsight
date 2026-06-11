#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()

int main(){
    int k,t;
    cin>>k>>t;
    vector<int> a(t);
    rep(i,t) cin>>a[i];

    sort(all(a));
    reverse(all(a));

    if(t==1){
        cout<<a[0]-1<<endl;
        return 0;
    }

    if(a[0]-1<=a[1]) cout<<0<<endl;
    else{
        int sum=0;
        for(int i=1;i<t;i++){
            sum+=a[i];
        }
        if(sum>=a[0]-1) cout<<0<<endl;
        else cout<<a[0]-1-sum<<endl;
    }
}
