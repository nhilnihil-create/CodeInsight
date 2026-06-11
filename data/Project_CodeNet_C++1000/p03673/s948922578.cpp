#include<bits/stdc++.h>
using namespace std;
using ll = long long;
using Graph = vector<vector<int>>;
#define ALL(x) (x).begin(), (x).end()
#define REP(i ,n) for(int i = 0; i < (int)(n); i++)
#define pb push_back
typedef vector<int>vint;
typedef vector<ll>vll;
template<typename T> istream &operator>>(istream &is, vector<T> &vec){ for (auto &v : vec) is >> v; return is; }
template<typename A,typename B>inline bool chmin(A &a,const B &b){if(a>b){a=b;return true;}else{return false;}}
template<typename A,typename B>inline bool chmax(A &a,const B &b){if(a<b){a=b;return true;}else{return false;}}

int main()
{
    ll N;
    cin >> N;
    vll A(N);
    cin >> A;
    deque<ll> que;
    REP(i,N){
        if(0 == i%2){
            que.push_back(A[i]);
        }else{
            que.push_front(A[i]);
        }
    }
    while(!que.empty()){
        if(0 == N%2){
            cout << que.front() << " ";
            que.pop_front();
        }else{
            cout << que.back() << " ";
            que.pop_back();
        }
    }
    cout << endl;
}