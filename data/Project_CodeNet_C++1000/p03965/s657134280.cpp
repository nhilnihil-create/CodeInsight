#define _GLIBCXX_DEBUG//TLEの原因になるので注意！！！！！！！！！！！
#include<cmath>
#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
vector<int> arr;
stack<int> st;
queue<int> qu;
queue<pair<int,int> > qu2;
priority_queue<int> pq;
#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define rep2(i,n) for(int i=1; i<=(int)(n); i++)
#define mins(x,y) x=min(x,y)
#define maxs(x,y) x=max(x,y)
typedef set<int> set_t;
typedef set<string> set_g;
typedef complex<double> xy_t;
static const int NIL = -1;
static const int INF = 1000000007;
#define mp make_pair
#define sz(x) int(x.xise())
#define mod 1000000007
#define reps(i,s,n) for(int i = s; i < n; i++)
//#define int long long

//cerrはコメントアウトしなくても通る//ただしTLEを引き起こすことがある

int p=0;//パーの残弾

int main(){
    string s;
    cin >> s;
    int n=s.size();
    int ans=0;
    rep(i,n){
        if(s[i]=='g'){
            if(p>0){
                p--;
                ans++;
            }else{
                p++;
            }
        }else{
            if(p>0){
                p--;
            }else{
                p++;
                ans--;
            }
        }
    }
    cout<<ans<<endl;
    return 0;
}