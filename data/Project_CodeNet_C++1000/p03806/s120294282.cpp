#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<(int)(n);i++)
using namespace std;
using ll = long long ;
using P = pair<int,int> ;
using pll = pair<long long,long long>;
constexpr int INF = 1e9;
constexpr long long LINF = 1e17;
constexpr int MOD = 1000000007;
constexpr double PI = 3.14159265358979323846;

int main(){
    int n,ma,mb;
    scanf("%d %d %d",&n,&ma,&mb);
    //cin >> n >> ma >> mb;
    vector<int> a(n),b(n),c(n);
    rep(i,n) scanf("%d %d %d",&a[i],&b[i],&c[i]);
    //rep(i,n) cin >> a[i] >> b[i] >> c[i];

    vector<P> one;
    map<int,int> two;
    for(int i=1;i<(1<<(n/2));i++){
        int aa = 0;
        int bb = 0;
        int cc = 0;
        rep(j,n/2){
            if(i>>j&1){
                aa += a[j];
                bb += b[j];
                cc += c[j];
            }
        }
        one.push_back(P(ma*bb-mb*aa,cc));
    }
    for(int i=1;i<(1<<((n+1)/2));i++){
        int aa = 0;
        int bb = 0;
        int cc = 0;
        rep(j,(n+1)/2){
            if(i>>j&1){
                aa += a[j+n/2];
                bb += b[j+n/2];
                cc += c[j+n/2];
            }
        }
        if(two.count(-ma*bb+mb*aa)==0){
            two[-ma*bb+mb*aa] = cc;
        }else{
            two[-ma*bb+mb*aa] = min(two[-ma*bb+mb*aa],cc);
        }
    }

    int ans = INF;
    if(two.count(0)>0) ans = two[0];
    rep(i,one.size()){
        if(one[i].first==0) ans = min(ans,one[i].second);
        if(two.count(one[i].first)==0) continue;

        ans = min(ans,two[one[i].first]+one[i].second);
    }
    printf("%d\n",(ans==INF?-1:ans));
    //cout << (ans==INF?-1:ans) << endl;

    //rep(i,one.size()) cout << one[i].first <<" " << one[i].second << endl;cout << endl;
    //for(auto p:two) cout << p.first <<" " << p.second << endl;
    return 0;
}
