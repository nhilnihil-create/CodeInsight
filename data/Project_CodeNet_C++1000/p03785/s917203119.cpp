#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define rep_bit(n) for (int bit = 0; bit < (1<<n); ++bit)
#define all(x) (x).begin(),(x).end()
#define ll long long
#define ld long double
#define CYES cout<<"Yes"<<endl
#define CNO cout<<"No"<<endl
#define SP <<" "<<
#define CST(x) cout<<fixed<<setprecision(x)
using namespace std;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<bool> vb;
typedef vector<string> vs;
typedef pair<int,int> pi;
typedef pair<ll,ll> pl;
typedef vector<pi> vpi;
typedef vector<pl> vpl;
typedef vector<vi> Graph;

//条件式 ? 真の場合の文 : 偽の場合の文
//abs(x) = (x の絶対値)
//string S  S,at(i),S += T,S += c,S.size(),S.substr(l)l文字目から最後まで,
///S.substr(l, r)l文字目からl+r-1文字目 n文字目から0個で空列を返せる
//*min_element(all(x)) *max_element(all(x))
//vi x; x.back(),x.front(),x.push_back(),x.pop_back()
//swap(a, b)
//gcd(a, b)最大公約数
//sort(all(x)),reverse(all(x)),sort(x.begin()+l,a.begin()+r)lからrまで
//stack<int> a; a.push(x),a.pop(),a.top(),a.empty()bool
//queue<int> b; b.push(x),b.pop(),b.front(),b.empty()bool,b.size() 要素が小さい順
//priority_queue<int, vector<int>, greater<int>> c,c.top()
//map<int, int> M1; 変数[key] = value; 変数.erase(key); 変数.at(key); 変数.count(key)所属判定　変数.size()
//find(all(x), key)boolソート済みのベクトル
//*lower_bound(all(x),k)以上の最小の要素,*uppper_bound(all(x),k)より大きい最小の要素
//char('0'+cnt) 数字cntからcharへの変換
//int(char-'0') charからintへの変換
int main(){

    int n;
    ll c,k;
    cin >> n >> c >> k;
    vl t(n);
    rep(i,n) cin >> t.at(i);
    sort(all(t));
    int ans = 1;
    int now = 0;
    rep(i,n){
        if(now+c==i || t.at(now)+k < t.at(i)){
            ans++;
            now = i;
        }
    }
    cout << ans << endl;
}
