#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vi;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef vector<char> vc;
typedef vector<ll> vll;
typedef vector<vector<int>> vvi;
typedef vector<vector<string>> vvs;
typedef vector<vector<char>> vvc;
typedef vector<vector<bool>> vvb;
typedef pair<int,int> P;
typedef pair<ll, ll> Pll;
#define vrep(v,n) for(int i=0;i<n;i++){cin >> v.at(i);} 
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define repn(i, n) for (int i = 0; i <= (int)(n); i++)
#define srep(i, l, n) for (int i = l; i < (int)(n); i++)
#define srepn(i, l, n) for (int i = l; i <= (int)(n); i++)
#define pb push_back 
template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

const int mod = 1000000007;
const int inf = 1e9;
#define PI 3.14159265369;
int dx[4] = {1,-1,0,0};
int dy[4] = {0,0,1,-1};
int ddx[8] = {1,1,1,-1,-1,-1,0,0};
int ddy[8] = {0,1,-1,0,1,-1,1,-1};


int main(){
    int n;
    cin >> n;
    ll ret = 0;
    ll sum = 0;
    while(n--){
        int a;
        cin >> a;
        if(a==0){
            ret += sum/2;
            sum = 0;
        }else{
            sum += a;
        }
        if(n==0){
            ret += sum/2;
        }
    }
    cout << ret << endl;
}