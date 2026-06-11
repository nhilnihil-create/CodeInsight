#include <bits/stdc++.h>
using namespace std;
#define int long long
#define All(v) (v).begin(),(v).end()
int dy[8] = {-1,0,1,0,-1,1,1,-1};
int dx[8] = {0,1,0,-1,1,1,-1,-1};
const int mod = 1000000007;
const int inf = mod*mod;
const int d5 = 100100;
signed main(){
    ios::sync_with_stdio(false);
    cin.tie(0);
    int n;
    cin>>n;
    vector<int> a(n),b(n);
    int cnt=0;
    for(int i=0;i<n;i++){
        cin>>a[i];
        b[i]=a[i];
    }
    sort(All(b));
    map<int,int> D;
    for(int i=0;i<n;i++)D[b[i]]=i;
    int res=0;
    for(int i=0;i<n;i++)res+=abs(i-D[a[i]])%2;
    cout<<res/2<<endl;
}