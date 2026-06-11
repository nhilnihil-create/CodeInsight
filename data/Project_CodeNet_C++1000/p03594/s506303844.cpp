#include <bits/stdc++.h>
const int INF=1e9;
const int MOD=1e9+7;
//const int MOD=998244353;
const long long LINF=1e18;
using namespace std;
#define int long long
//template
int c[3000][3000];
typedef pair<int,int> P;
std::vector<P> num(2000000,P(0,0));
int wa[3000][3000];
int d;
P grd,gld,brd,bld,ord,old,rrd,rld,rt,rb,gt,gb,ot,ob,bb,bt;
int po=0;
void draw(int y,int x,int color){
  for(int i=y;i<y+d;i++){c[i][x]=color;num[++po]=P(i,x);}
  if(color==1)rt=P(y,x);
  if(color==2)bt=P(y,x);
  if(color==3)ot=P(y,x);
  if(color==4)gt=P(y,x);
  if(color==1)rb=P(y+d-1,x);
  if(color==2)bb=P(y+d-1,x);
  if(color==3)ob=P(y+d-1,x);
  if(color==4)gb=P(y+d-1,x);
  for(int j=1;j<=(d-1)/2;j++){
    for(int i=y+j;i<y+d-j;i++){
      c[i][x+j]=c[i][x-j]=color;
      num[++po]=P(i,x+j);
      num[++po]=P(i,x-j);
    }
  }
  int j=(d-1)/2;
  if(color==1)rrd=P(y+d-j-1,x+j);
  if(color==2)brd=P(y+d-j-1,x+j);
  if(color==3)ord=P(y+d-j-1,x+j);
  if(color==4)grd=P(y+d-j-1,x+j);
  if(color==1)rld=P(y+d-j-1,x-j);
  if(color==2)bld=P(y+d-j-1,x-j);
  if(color==3)old=P(y+d-j-1,x-j);
  if(color==4)gld=P(y+d-j-1,x-j);
}
void warp(int y,int x){
  for(int i=y;i<y+d;i++){
    po++;
    if(i<0||x<0)continue;
    wa[i][x]=po;
  }
  for(int j=1;j<=(d-1)/2;j++){
    for(int i=y+j;i<y+d-j;i++){
      po++;
      if(i>=0&&x+j>=0)wa[i][x+j]=po;
      po++;
      if(i>=0&&x-j>=0)wa[i][x-j]=po;
    }
  }
}
//main
signed main(){
  int o=0;
  memset(c,0,sizeof(c));
  //memset(num,0,sizeof(num));
  //fill(num,P(0,0));
  memset(wa,0,sizeof(wa));
  int H,W;cin>>H>>W>>d;
  string s="WRGBY";
  int sw=(d%2==0);
  int width=d-sw;
  draw(0,width,1);
  draw(d/2,(d-1)/2,2);
  int a=(d+1)/2,b=a-(d&1);
  draw(d/2+a,(d-1)/2+b,3);
  draw(a,width+b,4);
  po=0;
  int tmp;
  if(d%2){
    warp(grd.first+1,grd.second);//red rd
    //cout<<num[wa[9][5]].first<<" "<<num[wa[9][5]].second<<endl;
    warp(rrd.first-(d-1),rrd.second+1);//blue ru
    //cout<<num[wa[9][5]].first<<" "<<num[wa[9][5]].second<<endl;
    warp(bld.first-d,bld.second);//ora lu
    //cout<<num[wa[9][5]].first<<" "<<num[wa[9][5]].second<<endl;
    warp(rld.first-d,rld.second);//gre lu
    //cout<<num[wa[9][5]].first<<" "<<num[wa[9][5]].second<<endl;
    po=0;
    warp(bld.first,bld.second-1);//red l
    //cout<<num[wa[9][5]].first<<" "<<num[wa[9][5]].second<<endl;
    warp(ord.first+1,ord.second);//blue rd
    //cout<<num[wa[9][5]].first<<" "<<num[wa[9][5]].second<<endl;
    warp(grd.first-(d-1),grd.second+1);//ora ru
    //cout<<num[wa[9][5]].first<<" "<<num[wa[9][5]].second<<endl;
    warp(old.first,old.second-1);//gre ld
    //cout<<num[wa[9][5]].first<<" "<<num[wa[9][5]].second<<endl;
  }
  else{
    warp(grd.first,grd.second+1);//red r
    po=0;
    warp(ob.first+1,ob.second);//red d
    warp(ord.first,ord.second+1);//blue rd
    tmp=po;
    warp(rt.first-d,rt.second);//ora u
    po=tmp;
    warp(bld.first-d,bld.second-1);//ora lu
    warp(old.first,old.second-1);//gre ld
    po=0;
    warp(bld.first,bld.second-1);//red l
    warp(rrd.first-d,rrd.second+1);//blue ru
    warp(grd.first-d,grd.second+1);//ora ru
    warp(rld.first-d,rld.second-1);//gre lu
  }
  P memo;
  int nowh=0,noww=width;
  //cout<<wa[9][5]<<" "<<num[wa[9][5]].first<<" "<<num[wa[9][5]].second<<endl;
  //cout<<c[5][1]<<endl;
  for(int i=0;i<H;i++){
    for(int j=0;j<W;j++,noww++){
      if(i&&j==0){nowh=memo.first+1,noww=memo.second;}
      //if(i==1&&j==2)cout<<nowh<<" "<<noww<<endl;
      if(c[nowh][noww]==0){
        int hh=nowh,ww=noww;
        nowh=num[wa[hh][ww]].first;
        noww=num[wa[hh][ww]].second;
      }
      //if(i==1&&j==2)cout<<nowh<<" "<<noww<<endl;
      if(j==0)memo=P(nowh,noww);
      //if(c[nowh][noww]==0)i/=o;
      cout<<s[c[nowh][noww]];
    }
    cout<<endl;
  }
}
