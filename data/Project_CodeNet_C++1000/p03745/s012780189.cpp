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
    int N;
    cin >> N;
    vll A(N);
    cin >> A;
    int flag = 0;
    if(A[0] > A[1])flag = -1;
    else if(A[0] < A[1])flag = 1;
    else flag = 0;

    int ans = 1;
    for(int i=2; i<N; i++){
        if(A[i-1] > A[i]){
            if(flag == 1){
                flag = 0;
                ans++;
            }else if(flag == 0)flag = -1;
        }
        else if(A[i-1] < A[i]){
            if(flag == -1){
                flag = 0;
                ans++;
            }else if(flag == 0)flag = 1;
        }
    }
    cout << ans << endl;
}