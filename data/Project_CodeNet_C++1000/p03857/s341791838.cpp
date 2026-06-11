#include<bits/stdc++.h>
#define pi 3.1415926535897932384626
using namespace std;
      
struct P{
  int x;
  long long y;
  /*bool operator < (const P &a )const{
    //if(y!=a.y)
    return y<a.y;
  };*/
};

int a,b,c,d,i,k,n,m,e,dx[10]={1,0,-1,0,1,1,-1,-1},dy[10]={0,1,0,-1,1,-1,1,-1};
int o[412111];
int l[1];
int j[1];

long long x,y,z,mod=1000000007;
//string r;
char r[3];

P u[1];
queue<P> q;
stack<int> s;
//set<int> s;
map<int,int> p[201010];

vector<int> v;


bool as(P a,P b)
{
  //if(a.x!=b.x)
  //return a.x<b.x;
  return a.y>b.y;
}

int f(int n)
{
  if(o[n]==n) return n;
  return o[n]=f(o[n]);
}

int main()
{
  scanf("%d %d %d",&a,&b,&c);
  iota(o+1,o+a*2+1,1);
  for(int t=1;t<=b;t++)
  {
    scanf("%d %d",&n,&m);
    o[f(n)]=f(m);
  }
  for(int t=1;t<=c;t++)
  {
    scanf("%d %d",&n,&m);
    n+=a,m+=a;
    o[f(n)]=f(m);
  }
  for(int t=1;t<=a;t++)
    p[f(t)][f(t+a)]++;
  for(int t=1;t<=a;t++)
  printf("%d ",p[f(t)][f(t+a)]);
}
//0
//11


