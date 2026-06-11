#include <bits/stdc++.h>
#define rep(i,n) for(int i=0;i<n;i++)
#define reps(i,s,n) for(int i=s;i<n;i++)
#define rep_bit(n) for (int bit = 0; bit < (1<<n); ++bit)
#define all(x) (x).begin(),(x).end()
#define pb push_back
#define ll long long
#define CYES cout<<"Yes"<<endl
#define CNO cout<<"No"<<endl
using namespace std;
typedef vector<vector<int> > Graph;
typedef vector<int> vi;
typedef vector<ll> vl;
typedef vector<bool> vb;
//abs(x) = (x の絶対値)
//string S  S[i],S += T,S += c,S.size(),S.substr(l),S.substr(l, r)
//*min_element(all(x)) *max_element(all(x))
//vi x; x.back(),x.front(),x.push_back(),x.pop_back()
//swap(a, b)
//gcd(a, b)最大公約数
//sort(all(x)),reverse(all(x)),sort(x.begin()+l,a.begin()+r)lからrまで
//stack<int> a; a.push(x),a.pop(),a.top(),a.empty()bool
//queue<int> b; b.push(x),b.pop(),b.front(),b.empty()bool
//priority_queue<int, vector<int>, greater<int>> c,c.top()
//map<int, int> M1;
//find(all(x), key)boolソート済みのベクトル
//lower_bound(all(x),k)以上,uppper_bound(all(x),k)より大きい
int main(){

    int N;
    cin >> N;
    vl vec;
    rep(i,3*N){
        ll a;
        cin >> a;
        vec.pb(a);
    }
    sort(all(vec));
    ll ans = 0;
    while(vec.size()>N){
        vec.pop_back();
        ans+=vec.back();
        vec.pop_back();
    }

    cout << ans << endl;
    return 0;
}
