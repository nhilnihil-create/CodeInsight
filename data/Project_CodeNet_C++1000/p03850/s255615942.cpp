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
long long o[122111];
long long l[111111];
long long j[1];

long long x,y,z,mod=1000000007;
//string r;
char r[3];

P u[1];
queue<P> q;
stack<int> s;
//set<int> s;
map<int,int> p;

vector<int> v;


bool as(P a,P b)
{
  //if(a.x!=b.x)
  //return a.x<b.x;
  return a.y>b.y;
}

int main()
{
  scanf("%d",&a);
  scanf("%d",&n);
  o[1]=l[1]=n;
  for(int t=2;t<=a;t++)
  {
    scanf("%s %d",r,&n);
    if(r[0]=='+') o[t]=o[t-1]+n,l[t]=l[t-1]+n;
    else
    {
      o[t]=o[t-1]-n,l[t]=l[t-1]+n;
      v.push_back(t);
    }
  }
  x=o[a];
  for(int h=0;h+1<v.size();h++)
  {
    x=max(x,o[v[h]-1]+l[a]-l[v[h+1]-1]-(l[v[h+1]-1]-l[v[h]-1]));
    //printf("%lld %lld %lld\n",o[v[h]-1],l[a]-l[v[h+1]-1],(l[v[h+1]-1]-l[v[h]-1]));
  }
  printf("%lld",x);
}
//0
//12


