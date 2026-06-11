#include <bits/stdc++.h>
using namespace std;
#define FOR(i,a,b) for(int i=(a);i<(b);++i)
#define rep(i,n)   FOR(i,0,n)
#define pb push_back
#define mp make_pair
typedef long long ll;
typedef pair<int,int> pint;

int a[5001];
int main(){
    int n,k;
    cin>>n>>k;
    rep(i,n) cin>>a[i];
    sort(a,a+n,greater<int>());
    int sum=0,ans=n;
    rep(i,n){
        if(sum+a[i]<k) sum+=a[i];
        else{
            ans=n-i-1;
        }
    }
    cout<<ans<<endl;
    return 0;
}