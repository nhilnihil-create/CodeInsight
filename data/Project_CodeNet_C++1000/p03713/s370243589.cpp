#include <bits/stdc++.h>
using namespace std;
long long area(long long a,long long b){
    long long sa,sb,sc,sbb,scc;
    long long ans=1e9;
    for(int i=1;i<a;i++){
        sa=i*b;
        sb=(a-i)/2*b;
        sc=(a-(a-i)/2-i)*b;
        sbb=(a-i)*(b/2);
        scc=(a-i)*(b-b/2);
        ans=min({ans,max({sa,sb,sc})-min({sa,sb,sc}),max({sa,sbb,scc})-min({sa,sbb,scc})});
    }
    return ans;
}
int main() {
    long long h,w;
    cin >> h >> w;
    long long ans1,ans2;
    ans1=area(h,w);
    ans2=area(w,h);
    cout << min(ans1,ans2) << endl;
}