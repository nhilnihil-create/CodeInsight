#include<bits/stdc++.h>
using namespace std;
char c[2][2]={'R','Y','G','B'};
char ma[2001][2001];
int d,f=0;

void dfs(int x,int y,int cn1,int cn2){
  //cout<<x<<" "<<y<<endl;
  cn1%=2;
  cn2%=2;
  if(x<0||y<0||x>=2000||y>=2000)return;
  if(ma[x][y]!='#')return;
    
  for(int i=-d/2;i<=d/2;i++)
    for(int j=-d/2;j<=d/2;j++){
      if(x+i<0||y+j<0||x+i>=2000||y+j>=2000)continue;
      if(abs(i)+abs(j)>d/2)continue;
      ma[x+i][y+j]=c[cn1][cn2];
    }

  dfs(x+d/2,y+d/2+1+f,cn1,cn2+1);
  dfs(x-d/2,y-d/2-1-f,cn1,cn2+1);
  dfs(x-d/2-1,y+d/2+f,cn1+1,cn2);
  dfs(x+d/2+1,y-d/2-f,cn1+1,cn2);
    
}

int main(){
  int h,w;
  cin>>h>>w>>d;
  if(d==1){
    char g[4]={'R','Y','G','B'};
    for(int i=0;i<h;i++){
      for(int j=0;j<w;j++){
	cout<<g[(j+i)%4];
      }
      cout<<endl;
    }
  }else if(d==2){
     char g[4]={'R','Y','G','B'};
    for(int i=0;i<h;i++){
      for(int j=0;j<w;j++){
	cout<<g[(j+(i/2)*2)%4];
      }
      cout<<endl;
    }
    
  }else{
    if(d%2==0)d--,f=1;
    for(int i=0;i<2000;i++)
      for(int j=0;j<2000;j++)
	ma[i][j]='#';
    dfs(0,0,0,0);
    for(int i=d;i<h+d;i++){
      for(int j=d;j<w+d;j++){
	if(ma[i][j]=='#')cout<<ma[i][j-1];
	else cout<<ma[i][j];
      }
      cout<<endl;
    }
  }
  return 0;
}
