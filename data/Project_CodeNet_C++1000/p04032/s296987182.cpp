#include <bits/stdc++.h>
using namespace std;
typedef long long int ll;
typedef long double ld;
template<class T> inline bool chmax(T& a, T b) { if (a < b) { a = b; return 1; } return 0; }
template<class T> inline bool chmin(T& a, T b) { if (a > b) { a = b; return 1; } return 0; }
const long long INF = 1LL << 60;
bool pairCompare(const pair<double,ll>& firstElof, const pair<double,ll>& secondElof){
    return firstElof.first < secondElof.first;
}
bool pairCompareSecond(const pair<double,ll>& firstElof, const pair<double,ll>& secondElof){
    return firstElof.second < secondElof.second;
}
#define MAX_N 100100
#define MOD 998244353
bool x[MAX_N];
ll num[MAX_N];
ll fibl[MAX_N]={0};
// 四方向への移動ベクトル
const int dx[4] = {1, 0, -1, 0};
const int dy[4] = {0, 1, 0, -1};

ll fib(ll a){
    if (fibl[a]!=0)return fibl[a];
    if (a==0){
        return 0;
    }else if (a==1){
        return 1;
    }
    return fibl[a]=fib(a-1)+fib(a-2);
}

ll eratosthenes(ll n) {
    int p = 0;
    for (ll i=0; i<=n; ++i) x[i] = true;
    x[0] = x[1] = false;
    for(int i=2; i<=n; ++i) {
        if(x[i]) {
            p++;
            for(int j=2*i; j<=n; j+=i) x[j] = false;
        }
        
        num[i] = p;
    }
    return p;
}
 
ll gcd(ll a,ll b){
    if (a%b==0)return(b);
    else return(gcd(b,a%b));
}
 
ll keta(ll N){
    int tmp{};
    while( N > 0 ){
        tmp += ( N % 10 );
        N /= 10;
    }
    N = tmp;
    return N;
}

void  base_num(ll data,ll base){
    if(data==0) return;
    ll next=abs(data)%abs(base);
    if(data<0) next=(abs(base)-next)%abs(base);
    base_num((data-next)/base,base);
    cout << next;
}

int main(){
    string s;
    cin >> s;
    if (s[0]==s[1]){
        cout << 1 << " " << 2 << endl;
        return 0;
    }else{
        for (ll i=2;i<s.size();i++){
            if (s[i]==s[i-1]){
                cout << i << " " << i+1 << endl;
                return 0;
            }else if (s[i]==s[i-2]){
                cout << i-1 << " " << i+1 << endl;
                return 0;
            }
        }
        
    }
    cout << -1 << " " << -1 << endl;
    return 0;
}

