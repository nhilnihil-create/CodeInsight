#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0; i<n; i++)
#define REP(i,m,n) for(ll i=(ll)(m);i<(ll)(n);i++)
#define fi first
#define se second
long long mo = 1000000007;
typedef long long ll;
typedef long double ld;
typedef pair<int,int> Pii;
typedef pair<ll,ll> Pll;
typedef pair<ll,Pll> PlP;
template<class T, class S> void cmin(T &a, const S &b) { if (a > b)a = b; }
template<class T, class S> void cmax(T &a, const S &b) { if (a < b)a = b; }
template<class A>void PR(A a,ll n){rep(i,n){if(i)cout<<' ';cout<<a[i];}cout << "\n";}
ld PI=3.14159265358979323846;

int main(){
    ll N,x;
    cin >> N >> x;
    deque<ll> que;
    if(x == 1 || x == 2*N-1){
        cout << "No" << endl;        
        return 0;
    }
    if(N == 2 && x != 2){
        cout << "No" << endl;
        return 0;
    }else if(N == 2 && x == 2){
        cout << "Yes" << endl;
        rep(i,3){
            cout << i+1 << endl;
        }
        return 0;
    }
    cout << "Yes" << endl;
    ll w,y,z;
    if(x == 2){
        w = x+1;
        y = x-1;
        z = x+2;
    }else{
        w = x-1;
        y = x+1;
        z = x-2;
    }
    ll cur = 1;
    rep(i,(N-2)){
        while(cur == w || cur == x || cur == y || cur == z){
            cur++;
        }
        cout << cur << endl;
        cur++;
    }
    cout << w << endl;
    cout << x << endl;
    cout << y << endl;
    cout << z << endl;
    rep(i,N-3){
        while(cur == w || cur == x || cur == y || cur == z){
            cur++;
        }
        cout << cur << endl;
        cur++;
    }

    /*
    que.push_back(x);
    REP(i,1,N-1){
        que.push_back(x+i);
        que.push_front(x-i);
    }
    if(que.front() < 1 || que.back() > 2*N - 1){
        cout << "No" << endl;
        return 0;
    }else if(que.front() == 1 && que.back() == 2*N - 1){
        cout << "No" << endl;
        return 0;
    }else if(que.front() == 1){
        cout << "Yes" << endl;
        que.push_back(2*N-2);
        que.push_front(2*N-1);
    }else if(que.back() == 2*N -1){
        cout << "Yes" << endl;
        que.push_back(1);
        que.push_front(2);
    }else{
        cout << "Yes" << endl;
        que.push_front(1);
        que.push_back(2*N-1);
    }
    rep(i,2*N-1){
        cout << que[i] << endl;
    } */
}
