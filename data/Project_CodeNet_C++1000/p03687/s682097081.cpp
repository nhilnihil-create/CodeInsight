#pragma GCC optimize("Ofast")
#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define cinf(n,x) for(int i=0;i<(n);i++)cin>>x[i];
#define ft first
#define sc second
#define pb push_back
#define lb lower_bound
#define ub upper_bound
#define all(v) (v).begin(),(v).end()
#define LB(a,x) lb(all(a),x)-a.begin()
#define UB(a,x) ub(all(a),x)-a.begin()
#define mod 1000000007
#define FS fixed<<setprecision(15)
using namespace std;
typedef long long ll;
template<class T> using V=vector<T>;
using Graph = vector<vector<int>>;
using P=pair<ll,ll>;
typedef unsigned long long ull;
typedef long double ldouble;
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return true; } return false; }
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return true; } return false; }

const ll INF=1e18;

int main(){
    cin.tie(0);ios::sync_with_stdio(false);
    string s;
    cin>>s;
    set<char> st;
    int n=s.size();
    rep(i,n) st.insert(s[i]);
    int ans=10000;
    for(char x:st){
        int cnt=0;
        string t=s;
        while(true){
            string u;
            bool ok=1;
            rep(i,t.size()-1){
                if(t[i]==x||t[i+1]==x) u+=x;
                else{
                    ok=0;
                    u+=t[i];
                }
            }
            
            cnt++;
            if(ok) break;
            t=u;
        }
        chmin(ans,cnt);
    }
    if(st.size()==1) ans=0;
    cout<<ans<<endl;
}
//ペナルティ出しても焦らない　ACできると信じろ！！！
//どうしてもわからないときはサンプルで実験　何か見えてくるかも
//頭で考えてダメなら紙におこせ！！
/*
V,P(大文字)使用不可
乗算などの際にオーバーフローに注意せよ！
(適切にmodをとれ　にぶたんで途中で切り上げろ)
制約をよく読め！
(全探索できるなら全探索しろ)
stringの計算量(扱い)注意
コーナー注意！(特に数値が小さいものについては要検証)
N行出力のときは'\n'
グリッド上では行先が範囲内におさまるかif文で確認(RE注意)
if文ではちゃんと比較演算子==を使え(=でもエラー出ない)
配列(vector)の大きさが0か1以上かで場合分けせよ(RE注意)
(vector<int> a(m)でm==0というものはできない)
modはなるべく最後に取れ！
*/