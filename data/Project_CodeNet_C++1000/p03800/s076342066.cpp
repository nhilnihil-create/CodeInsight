#include <iostream>
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <vector>
#include <list>
#include <set>
#include <map>
#include <queue>
#include <stack>
#include <cctype>
#include <cassert>
#include <climits>
#include <string>
#include <bitset>
#include <cfloat>
#include <unordered_set>
#pragma GCC optimize("Ofast")
using namespace std;
typedef long double ld;
typedef long long int ll;
typedef unsigned long long int ull;
typedef vector<int> vi;
typedef vector<char> vc;
typedef vector<bool> vb;
typedef vector<double> vd;
typedef vector<string> vs;
typedef vector<ll> vll;
typedef vector<pair<int,int> > vpii;
typedef vector<vector<int> > vvi;
typedef vector<vector<char> > vvc;
typedef vector<vector<string> > vvs;
typedef vector<vector<ll> > vvll;
#define rep(i,n) for(int i = 0; i < (n); ++i)
#define rrep(i,n) for(int i = 1; i <= (n); ++i)
#define irep(it, stl) for(auto it = stl.begin(); it != stl.end(); it++)
#define drep(i,n) for(int i = (n) - 1; i >= 0; --i)
#define fin(ans) cout << (ans) << '\n'
#define STI(s) atoi(s.c_str())
#define mp(p,q) make_pair(p, q)
#define pb(n) push_back(n)
#define all(a) a.begin(), a.end()
#define rall(a) a.rbegin(), a.rend()
#define Sort(a) sort(a.begin(), a.end())
#define Rort(a) sort(a.rbegin(), a.rend())
#define MATHPI acos(-1)
#define itn int;
int dx[8] = {1, 0, -1, 0, 1, -1, -1, 1};
int dy[8] = {0, 1, 0, -1, 1, 1, -1, -1};
template <class T> inline bool chmax(T& a,T b){if(a<b){a=b;return 1;} return 0;}
template <class T> inline bool chmin(T& a,T b){if(a>b){a=b;return 1;} return 0;}
struct io{io(){ios::sync_with_stdio(false);cin.tie(0);}};
const int INF = INT_MAX;
const ll LLINF = 1LL<<60;
const ll MOD = 1000000007;
const double EPS = 1e-9;


void umeru(string &s,vc &v,int n){
    if(v[0]=='S'){
        if(s[0]=='o'){
            v[n-1]=v[1];
        } else {
            if(v[1]=='W')v[n-1]='S';
            else v[n-1]='W';
        }
    } else{
        if(s[0]=='o'){
            if(v[1]=='W')v[n-1]='S';
            else v[n-1]='W';
        } else {
            v[n-1]=v[1];
        }
    }
    for(int i=1;i<n-2;i++){
        if(v[i]=='S'){
            if(s[i]=='o'){
                v[i+1]=v[i-1];
            } else {
                if(v[i-1]=='W')v[i+1]='S';
                else v[i+1]='W';
            }
        } else{
            if(s[i]=='o'){
                if(v[i-1]=='W')v[i+1]='S';
                else v[i+1]='W';
            } else {
                v[i+1]=v[i-1];
            }
        }
    }
}

bool judge(string &s,vc &v,int n){
    bool ch=true;
    rep(i,n){
        if(v[i]=='S'){
            if(s[i]=='o'){
                if(v[(i-1+n)%n]!=v[(i+1)%n])ch=false;
            } else {
                if(v[(i-1+n)%n]==v[(i+1)%n])ch=false;
            }
        } else {
            if(s[i]=='o'){
                if(v[(i-1+n)%n]==v[(i+1)%n])ch=false;
            } else {
                if(v[(i-1+n)%n]!=v[(i+1)%n])ch=false;
            }
        }
    }
    return ch;
}

int main(void) {
    
    int n;
    cin>>n;
    string s;
    cin>>s;
    vc v(n);
    rep(i,4){
        v.clear();
        if(i==0){
            v[0]='S';
            v[1]='S';
        } else if(i==1){
            v[0]='S';
            v[1]='W';
        } else if(i==2){
            v[0]='W';
            v[1]='S';
        } else if(i==3){
            v[0]='W';
            v[1]='W';
        }
        umeru(s,v,n);
        if(judge(s,v,n)){
            rep(i,n){
                cout<<v[i];
            }
            cout<<endl;
            return 0;
        }
    }
    fin(-1);
}