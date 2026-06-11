#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define repr(i,a,b) for(ll i=a;i<b;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define invrepr(i,a,b) for(int i=b-1;i>=a;i--)
#define invrep(i,n) invrepr(i,0,n)
#define repitr(itr,a) for(auto itr=a.begin();itr!=a.end();++itr)
const int MOD=1e9+7;


vector<int> deduplicate(vector<int> a) {
    sort(a.begin(),a.end());
    auto itr=unique(a.begin(),a.end());
    a.resize(itr-a.begin());
    return a;
}

int main() {
    ios_base::sync_with_stdio(false); 

    int a,b,c,d,e,f;
    cin >> a >> b >> c >> d >> e >> f;
    vector<int> xx,yy;
    rep(i,3010) {
        rep(j,3010) {
            int s=a*100*i+b*100*j;
            int t=c*i+d*j;
            if (s>0 && s<=f) xx.push_back(s);
            if (t>=0 && t<=f) yy.push_back(t);
        }
    }
    vector<int> x=deduplicate(xx),y=deduplicate(yy);
    double r=0;
    int sw=a*100,su=0;
    rep(i,x.size()) {
        rep(j,y.size()) {
            if (x[i]+y[j]<=f && 1.0*y[j]/(x[i]+y[j])>r && 1.0*y[j]/(x[i]+y[j])<=1.0*e/(100+e)) {
                r=1.0*y[j]/(x[i]+y[j]);
                sw=x[i]+y[j];
                su=y[j];
            }
        }
    }
    cout << sw << ' ' << su << endl;

    return 0;
}