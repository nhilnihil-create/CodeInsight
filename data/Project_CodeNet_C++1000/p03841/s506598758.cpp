#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <set>
#include <queue>
#include <stack>
#include <tuple>
#include <cmath>
#include <iomanip>
#define ll long long
#define rep(i,n) for(int i=0;i<(n);i++)
#define fi first
#define se second
using namespace std;
template<typename T1,typename T2> inline void chmin(T1 &a,T2 b){if(a>b) a=b;}
template<typename T1,typename T2> inline void chmax(T1 &a,T2 b){if(a<b) a=b;}
typedef pair<int,int> P;
//小数点以下　cout << fixed << setprecision(10) << num << endl;
//桁数はlog10(mid)でやれ　log(mid)/log(10)はWA
const int INF = 100100100;
int main(){
    int n; cin >> n;
    int x[n];
    vector<P> v;
    int s[n*n];
    rep(i,n*n) s[i]=INF;
    rep(i,n){
        cin >> x[i];
        x[i]--;
        s[x[i]]=i;
        v.push_back({x[i],i});
    }
    sort(v.begin(),v.end());
    int st=0;
    rep(i,v.size()){
        P d=v[i];
        rep(i,d.se){
            if(s[st]==INF) s[st]=d.se;
            else{
                st++;
                i--;
            }
            if(st>=n*n){
                cout << "No" << endl;
                break;
            }
        }
    }
    int ss=0;
    rep(i,v.size()){
        P d=v[i];
        rep(i,n-d.se-1){
            if(s[ss]==INF) s[ss]=d.se;
            else{
                ss++;
                i--;
            }
        }
        if(ss>=n*n){
            cout << "No" << endl;
            break;
        }
    }
    //判定は
    int cnt[n];
    rep(i,n+1) cnt[i]=0;
    rep(i,n*n){
        cnt[s[i]]++;
        if(i==x[s[i]] && cnt[s[i]]!=s[i]+1){
            cout << "No" << endl;
            return 0;
        }
    }
    cout << "Yes" << endl;
    rep(i,n*n) cout << s[i]+1 << " ";
    
    
}
