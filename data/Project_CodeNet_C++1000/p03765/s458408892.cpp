#include <bits/stdc++.h>
using namespace std;
#define pp pair<int,int>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define ll long long
#define all(a) (a).begin(),(a).end()
ll MOD=1000000007;
ll mod=998244353;
int inf=1000001000;
ll INF=10000000000000000;

int main(){
    string s,t;
    cin >> s >> t;
    vector<int> ss(s.size()+1,0),tt(t.size()+1,0);
    rep(i,s.size()) {
        if (s.at(i)=='A') ss.at(i+1)=ss.at(i)+1;
        else ss.at(i+1)=ss.at(i)+2;
    }
    rep(i,t.size()){
        if (t.at(i)=='A') tt.at(i+1)=tt.at(i)+1;
        else tt.at(i+1)=tt.at(i)+2;
    }
    int q;
    cin >> q;
    rep(i,q){
        int a,b,c,d;
        cin >> a >> b >> c >> d;
        if ((ss.at(b)-ss.at(a-1))%3==(tt.at(d)-tt.at(c-1))%3) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
}
