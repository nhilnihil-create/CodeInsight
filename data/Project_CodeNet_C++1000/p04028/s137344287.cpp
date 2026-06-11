#include<bits/stdc++.h>
using namespace std; 

typedef long long ll; 
#define sz(a) ((int)(a.size()))

const int mod=1e9+7; 
int mul(int a, int b){
  return (ll)a*b%mod; 
}
void add_self(int &a, int b){
  a+=b; 
  if(a>= mod) a-=mod; 
}
void mul_self(int &a, int b){
  a=(ll)a*b%mod; 
}
void sub_self(int &a, int b){
  a-=b; 
  if(a<0) a+=mod;
}
int exp(int a, int b){
  int ret=1; 
  while(b){
    if(b%2){
      mul_self(ret,a); 
    }
    mul_self(a,a); 
    b/=2; 
  }
  return ret; 
}
//--------------------------------------------------
int n,m; 
string s; 
int dp[5005][5005]; 

int get_num(int n,int m){
  if(n==m ) return 1;
  if(n<m) return 0; 
  if(n==1 && m==0) return 1; 
  if(dp[n][m]!=-1) return dp[n][m]; 
  int ans=0;
  if(m==0) ans=get_num(n-1,0); 
  if(m>0){
    ans=get_num(n-1,m-1);
  }
  add_self(ans,2*get_num(n-1,m+1)%mod); 
  return dp[n][m]=ans; 
}

void solve(){ 
  cin>>n; 
  cin>>s; 
  m=sz(s); 
  for(int i=0;i<=n;i++) s.push_back('*'); 
  memset(dp,-1,sizeof(dp)); 
  cout<<get_num(n,m)<<endl; 
}

int main(){
  clock_t beg=clock(); 
  solve(); 
  clock_t end=clock(); 
  fprintf(stderr,"%.2lf sec\n",(double)(end-beg)/CLOCKS_PER_SEC); 
}