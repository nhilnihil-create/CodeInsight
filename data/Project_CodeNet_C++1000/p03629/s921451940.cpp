#include <iostream>
#include <string.h>
#include <stdio.h>
#include <map>
#include <vector>
#include <math.h>
#include <algorithm>
#include <queue>
#include <set>
#include <tuple>
using namespace std;

#define rep(i,a) for(int i=0; i<a; i++)
#define rrep(i,a) for(int i=a; i>=0; i--)
#define rep1(i,a) for(int i=1; i<=a; i++)
#define cout1(a) cout << a << endl;
#define cout2(a,b) cout << a << " " << b << endl;
#define cout3(a,b,c) cout << a << " " << b << " " << c << endl;
#define cout4(a,b,c,d) cout << a << " " << b << " " << c << " " << d << endl;
#define mem(a,n) memset( a, n, sizeof(a))
#define all(a) a.begin(),a.end()

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef vector<int> V;
typedef vector<V> VV;
typedef vector<VV> VVV;
const int INF = 1e9;
const int MOD = 1e9+7;
const ll LLINF = 1e18;
static const double pi = 3.141592653589793;

int N;
string s;
int nex[200009][26];
int ne[26];
int len[200009], ta[200009];

int main() {
    cin.tie(0);
    ios::sync_with_stdio(false);
    
    cin>>s;
    N=s.size();
    
    rep(i,26) ne[i]=nex[N+1][i]=N+1;
    rrep(i,N){
        len[i]=200009;
        rep(j,26){
            nex[i][j]=ne[j];
            int x=len[ne[j]];
            if(x<len[i]){
                len[i]=x;
                ta[i]=j;
            }
        }
        len[i]++;
        if(i) ne[s[i-1]-'a']=i;
    }
    
    string R;
    int cur=0;
    while(cur!=N+1){
        R+='a'+ta[cur];
        cur=nex[cur][ta[cur]];
    }
    cout1(R);
}