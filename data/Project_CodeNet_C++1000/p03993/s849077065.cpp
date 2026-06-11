#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)n;i++)
#define rep1(i,n) for(int i=1;i<=(int)n;i++)
#define rep2(i,j,n) for(int j=i;j<n;j++)
#define rep3(i,j,n) for(int j=i;j<=n;j++)
#define rrep(i,n) for(int i=n-1;i>=0;i--)
#define sp(n) cout << fixed << setprecision(n)
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
typedef long long ll;
using namespace std;
int main(void){
    int n;cin>>n;
    vector<int> a(n);
    int res=0;
    rep(i,n){
        cin>>a[i];
        if(a[i]<i+1){
            if(a[a[i]-1]==i+1)res++;
        }
    }
    cout<<res<<endl;
}