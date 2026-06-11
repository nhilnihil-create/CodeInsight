#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int MOD=1000000007;
#define INF 1LL<<30
#define rep(i,n) for (int i = 0; i < (n); ++i)
#define all(x) (x).begin(),(x).end()


int main(){
    int n;
    cin>>n;
    vector<int> a(n);
    rep(i,n) cin>>a[i];

    int ans=1;
    int j=-1;
    rep(i,n-1){
        if(j==-1){
            if(a[i]<a[i+1]) j=1;
            else if(a[i]>a[i+1]) j=0;
        }
        else{
            if(j==1 && a[i]>a[i+1]){
                ans++;
                j=-1;  
            }
            else if(j==0 && a[i]<a[i+1]){
                ans++;
                j=-1;
            }
        }
    }

    cout<<ans<<endl;
}

