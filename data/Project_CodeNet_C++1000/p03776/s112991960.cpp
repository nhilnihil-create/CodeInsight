#include<bits/stdc++.h>
using namespace std;
#define rep(i,j,n) for(int i=(int)(j);i<(int)(n);i++)
#define REP(i,j,n) for(int i=(int)(j);i<=(int)(n);i++)
#define int long long
#define ALL(a) (a).begin(),(a).end()
#define vi vector<int>
#define vii vector<vi>
#define pii pair<int,int>
#define priq priority_queue<int>
#define disup(A,key) distance(A.begin(),upper_bound(ALL(A),(int)(key)))
#define dislow(A,key) distance(A.begin(),lower_bound(ALL(A),(int)(key)))
#define tii tuple<int,int,int>
#define Priq priority_queue<int,vi,greater<int>>
#define pb push_back
#define mp make_pair
#define INF (1ll<<60)
const int MAX_C = 1000;
long long Com[MAX_C][MAX_C];

void calc_com() {
    memset(Com, 0, sizeof(Com));
    Com[0][0] = 1;
    for (int i = 1; i < MAX_C; ++i) {
        Com[i][0] = 1;
        for (int j = 1; j < MAX_C; ++j) {
            Com[i][j] = (Com[i-1][j-1] + Com[i-1][j]) ;
        }
    }
}
signed main(){
  calc_com();
  int N,A,B; cin>>N>>A>>B;
  vi C(N);
  rep(i,0,N) cin>>C[i];
  sort(ALL(C),greater<int>());
  int sum=0;
  rep(i,0,A) sum+=C[i];
  double ans=sum*1.0/A;
  printf("%.10lf\n",ans);
  int Ans=1;
  int E=0,D=0;
  rep(i,0,A){
    if(C[i]==C[A-1]) D++;
  }
  rep(i,A,N){
    if(C[i]==C[A-1]) E++;
  }
  Ans*=Com[D+E][D];
  if(C[0]==C[A-1]){
    REP(i,A+1,min(B,D+E)){
      Ans+=Com[D+E][i];
    }
  }
  cout<<Ans<<endl;
  }

