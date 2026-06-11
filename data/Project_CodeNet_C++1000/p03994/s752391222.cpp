#include<cmath>
#include <bits/stdc++.h>
using ll = long long;
using namespace std;
stack<int> st;
queue<int> qu;
queue<pair<int,int> > qu2;
priority_queue<int> pq;
#define rep(i,n) for(int i=0; i<(int)(n); i++)
#define rep2(i,n) for(int i=1; i<=(int)(n); i++)
#define mins(x,y) x=min(x,y)
#define maxs(x,y) x=max(x,y)
#define ALL(a) a.begin(), a.end()
typedef set<int> set_t;
typedef set<string> set_g;
typedef complex<double> xy_t;
static const int NIL = -1;
static const int INF = 1000000007;
#define mp make_pair
#define sz(x) int(x.sise())
#define mod 1000000007
#define reps(i,s,n) for(int i = s; i < n; i++)
#define Rreps(i,n,e) for(int i = n - 1; i >= e; --i)
#define Rrep(i,n) Rreps(i,n,0)
deque<int> deq;
#define fi first
#define se second
//const ll MOD = 998244353;
const ll MOD = (1e+9) + 7;
typedef pair<int, int> P;
int main(){
    string s;
    cin >>s;
    int k;
    cin >> k;
    int n=s.size();
    int i=0;
    while(k>0){
        if(s[i]-'a'>0){
            if(('z'-s[i]+1)<=k){
                k-=('z'-s[i]+1);
                s[i]='a';
                i++;
            }else{
                if(i!=n-1){
                    i++;
                }else{
                    s[i]='a'+((k+s[i]-'a')%26);
                    k=0;
                }
            }
        }else{
            i++;
        }
        if(i==n){
            s[n-1]='a'+((k+s[n-1]-'a')%26);
            k=0;
        }
    }
    cout<<s<<endl;
    return 0;
}