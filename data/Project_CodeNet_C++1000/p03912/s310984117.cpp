#include<bits/stdc++.h>
using namespace std;
#define fs first
#define sc second
#define pb push_back
#define mp make_pair
#define eb emplace_back
#define ALL(A) A.begin(),A.end()
#define RALL(A) A.rbegin(),A.rend()
typedef long long LL;
typedef pair<LL,LL> P;
const LL mod=1000000007;
const LL LINF=1LL<<60;
const int INF=1<<30;
int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};



int main(){
    int n,m;cin >> n >> m;
    vector<int> x(n),v(m,0),vv(m,0);
    map<int,int> ma;
    for(int i=0;i<n;i++){
        cin >> x[i];
        ma[x[i]]++;
        v[x[i]%m]++;
    }
    for(auto p:ma){
        vv[p.fs%m] += p.sc / 2;
    }
    LL ans = 0;
    for(int i=0;i<=m/2;i++){
        if((m%2==0&&i==m/2)||i==0){
            ans += v[i] / 2;
        }
        else{
            if(v[i]<v[m-i]){
                ans += v[i];
                ans += min(vv[m-i],(v[m-i] - v[i]) / 2);
            }
            else{
                ans += v[m-i];
                ans += min(vv[i],(v[i] - v[m-i]) / 2);
            }
        }
    }
    cout << ans << endl;
    return 0;
}