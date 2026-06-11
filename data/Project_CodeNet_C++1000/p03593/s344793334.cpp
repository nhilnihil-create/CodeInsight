#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
#define repr(i,a,b) for(int i=a;i<b;i++)
#define rep(i,n) for(int i=0;i<n;i++)
#define invrepr(i,a,b) for(int i=b-1;i>=a;i--)
#define invrep(i,n) invrepr(i,0,n)
#define repitr(itr,a) for(auto itr=a.begin();itr!=a.end();++itr)
#define P pair<int,int>
const int MOD=1e9+7;
const int INF=1e9;
const double PI=acos(-1);

vector<int> vectorCnt(vector<char> a) {
    sort(a.begin(),a.end());
    int n=a.size();
    vector<int> b;
    int cnt=1;
    rep(i,n-1) {
            if (a[i+1]!=a[i]) {
                b.push_back(cnt);
                cnt=1;
            } else {
                ++cnt;
            }
    }
    b.push_back(cnt);
    return b;
}

int main() {
    ios_base::sync_with_stdio(false); 

    int h,w;
    cin >> h >> w;
    vector<char> a(h*w);
    rep(i,h) {
        rep(j,w) cin >> a[w*i+j];
    } 
    vector<int> b=vectorCnt(a);
    int m=b.size();
    vector<int> c(3);
    rep(i,m) { 
        if (b[i]%2==1) ++c[0];
        else if (b[i]%4==2) ++c[1];
        else ++c[2];
    }
    bool flag=1;
    if (h%2==0 && w%2==0) {
        if (c[0]>0 || c[1]>0) flag=0;
    } else if (h%2==0) {
        if (c[0]>0 || c[1]*2>h) flag=0;
    } else if (w%2==0) {
        if (c[0]>0 || c[1]*2>w) flag=0; 
    } else {
        if (c[0]>1 || c[1]*2>w-1+h-1) flag=0;
    }
    if (flag) cout << "Yes" << endl;
    else cout << "No" << endl;
    
    
    

    return 0;
}
