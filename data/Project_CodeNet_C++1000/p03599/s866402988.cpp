#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ld;
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
    int a, b, c, d, e, f;
    cin >> a >> b >> c >> d >> e >> f;
    a *= 100;b *= 100;
    ld dense = -1;
    int sugar = 0, water = 0;
    for(int i = 0; a*i <= f;i++){
        for(int j = 0; a*i+b*j<=f;j++){
            if(i==0 && j==0) continue;
            for(int k = 0; a*i+b*j+c*k<=f; k++){
                for(int l = 0; a*i+b*j+c*k+d*l<=f;l++){
                    ld nowwater = a*i+b*j;
                    ld nowsugar = c*k+d*l;
                    if(nowsugar/(nowwater/100) > e) continue;
                    ld nowdense = nowsugar/(nowwater+nowsugar);
                    if(dense < nowdense){
                        dense = nowdense;
                        water = nowwater;
                        sugar = nowsugar;
                    }
                }
            }
        }
    }
    cout << water+sugar << " " << sugar << endl;

}