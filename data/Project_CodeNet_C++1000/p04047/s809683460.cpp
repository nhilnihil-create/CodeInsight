#include <bits/stdc++.h>

#define PI 3.14159265359
#define rep(i,a,n) for(int i=a;i<(int)n;++i)
#define SZ(x) ((int)(x).size())	//size() unsigned -> int
#define descSort(a) sort(a.begin(),a.end(),std::greater<int>())
using namespace std;
typedef long long ll;
const ll INF = 1e9 + 7;

int main() {
    int n;
    cin>>n;
    vector<int> l(2*n);
    rep(i,0,2*n)cin>>l[i];

    sort(l.begin(),l.end());

    int ans=0;
    for(int i=0;i<2*n;i+=2) ans+=l[i];

    cout<<ans<<endl;
    return 0;
}