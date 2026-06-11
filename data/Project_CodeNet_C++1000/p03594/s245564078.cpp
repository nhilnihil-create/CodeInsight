#include<bits/stdc++.h>

#define pii pair<int,int>
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define eb emplace_back
#define pf push_front
#define pb2 pop_back
#define pf2 pop_front
#define line printf("\n")
#define pq priority_queue
#define rep(k,i,j) for(int k = (int)i;k<(int)j;k++)
#define repd(k,i,j) for(int k = (int)i;k>=(int)j;k--)
#define ll long long
#define ALL(a) a.begin(),a.end()
#define sz(a) int((a).size())
#define vi vector<int>

using namespace std;

double EPS = 1e-9;
int INF = 1e9+7;;
long long INFLL = 1e17;
double pi = acos(-1);
int dirx[8] = {-1,0,0,1,-1,-1,1,1};
int diry[8] = {0,1,-1,0,-1,1,-1,1};

clock_t first_attempt = clock();
inline void cek_time(){
	clock_t cur = clock()- first_attempt;
	cerr<<"TIME : "<<(double) cur/CLOCKS_PER_SEC<<endl;
}
inline void OPEN (string s) {
  freopen ((s + ".in").c_str (), "r", stdin);
  freopen ((s + ".out").c_str (), "w", stdout);
}

//end of template

int n,m,d;

const int maxn = 3005;
int ret[maxn][maxn],buck[maxn][maxn];

char ans[maxn][maxn];
int main(){
    cin>>n>>m>>d;
    
    memset(buck,-1,sizeof buck);
    rep(k,0,d)rep(i,0,d)buck[k][i] = 0;
    rep(k,0,d)rep(i,0,d)buck[k+d][i] = 1;
    rep(k,0,d)rep(i,0,d)buck[k][i+d] = 2;
    rep(k,0,d)rep(i,0,d)buck[k+d][i+d] = 3;
    
    rep(k,0,maxn)rep(i,0,maxn)if(buck[k][i]==-1){
        if(k-2*d>=0)buck[k][i] = buck[k-2*d][i];
        if(i-2*d>=0)buck[k][i] = buck[k][i-2*d];
    }
    char s[4] = {'R','Y','G','B'};
    
    memset(ret,-1,sizeof ret);
    rep(k,0,n)rep(i,0,m){
        ans[k][i] = s[buck[k+i+505][k-i+505]];
    }
    
    rep(k,0,n)printf("%s\n",ans[k]);
}