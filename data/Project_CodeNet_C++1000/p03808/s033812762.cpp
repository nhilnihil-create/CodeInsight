#include <bits/stdc++.h>
using namespace std;
struct Fast {Fast(){std::cin.tie(0);ios::sync_with_stdio(false);cout.precision(20);}} fast;

/* define */
#define FOR(I,X,Y) for(long long (I)=(X);(I)<(Y);(I)++)
#define REP(I,X,Y) for(long long (I)=(Y)-1;(I)>=(X);(I)--)
#define ALL(X) (X).begin(),(X).end()
#define pb push_back
#define COUNT(V,X) (upper_bound((V).begin(),(V).end(),X)-lower_bound((V).begin(),(V).end(),X))
#define debug(x) cerr<<#x<<':'<<x<<endl;
#define DEBUG(v) cerr<<#v<<':';for(auto xXx:v)cerr<<xXx<<' ';cerr<<endl;
#define Yes(X) if(X){cout<<"Yes"<<endl;}else{cout<<"No"<<endl;}
#define YES(X) if(X){cout<<"YES"<<endl;}else{cout<<"NO"<<endl;}
#define ctoi(C) (C-'0')

/* alias */
using ll = long long;
using ld = long double;
using vi = vector<int>;
using vii = vector<vector<int>>;
using vl = vector<long long>;
using vll = vector<vector<long long>>;
using pi = pair<int,int>;
using pl = pair<long long,long long>;
template<typename T> using PQ = priority_queue<T>;
template<typename T> using minPQ = priority_queue<T, vector<T>, greater<T>>;

/* const */
const long long dx[] = {1,0,-1,0};
const long long dy[] = {0,1,0,-1};
const long long dx8[] = {1,1,0,-1,-1,-1,0,1};
const long long dy8[] = {0,1,1,1,0,-1,-1,-1};
const long long dx9[] = {1,1,0,-1,-1,-1,0,1,0};
const long long dy9[] = {0,1,1,1,0,-1,-1,-1,0};
const int INF = 1000000007;
const long long LINF = 1000000000000000007;

/* func */
template <typename T> inline bool chmin(T& a, const T& b) {if (a > b) a = b; return a > b;}
template <typename T> inline bool chmax(T& a, const T& b) {if (a < b) a = b; return a < b;}
long long max(long long x,int y){return max(x,(long long)y);}
long long max(int x,long long y){return max((long long)x,y);}
long long min(long long x,int y){return min(x,(long long)y);}
long long min(int x,long long y){return min((long long)x,y);}

/* liblary */



/* main */

bool check(vl d,vl A){
    vl copy = d,yay(d.size(),0);
    ll N = d.size();
    ll MAX = *max_element(ALL(d));
    FOR(i,0,N)d[i] -= MAX;
    ll counter = 0;
    FOR(i,0,N){
        if(d[i]%N)return 0;
        counter += d[i]/N;
    }
    FOR(i,0,N){
        yay[i] -= counter;
        yay[i] += d[i];
    }
    ll sum = 0;
    FOR(i,0,N)sum += A[i];
    if(sum%((N)*(N+1)/2))return 0;
    return (sum/((N)*(N+1)/2)+counter)%N == 0 && sum/((N)*(N+1)/2)+counter >= 0 && copy == yay;
}

signed main(){
    ll N;
    cin >> N;
    vl A(N);
    FOR(i,0,N)cin >> A[i];
    vl d(N);
    d[0] = A[0] - A[N-1];
    FOR(i,1,N)d[i] = A[i] - A[i-1];
    YES(check(d,A));
}