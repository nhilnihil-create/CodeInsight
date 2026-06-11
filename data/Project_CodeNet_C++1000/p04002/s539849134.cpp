#include<bits/stdc++.h>

using namespace std;

map<int,map<int,bool> > data;
long long rem[10];
int posx[]={-1,0,1};
int posy[]={-1,0,1};
int h,w,n;

int chk(int x,int y)
{
  int r=0;

  for(int c=0;c<3;c++)
  for(int c2=0;c2<3;c2++)
  {
    if (data.find(x+posx[c])!=data.end()&&data[x+posx[c]].find(y+posy[c2])!=data[x+posx[c]].end())r++;
  }
  return r;
}

int main()
{
  int x,y;

  scanf("%d%d%d",&h,&w,&n);
  rem[0]=((long long)h-2)*(w-2);
  while(n--)
  {
    scanf("%d%d",&x,&y);
    if (data[x].find(y)==data[x].end())
    {
      for(int c=0;c<3;c++)
      for(int c2=0;c2<3;c2++)
      {
        if (x+posx[c]>1&&x+posx[c]<h&&y+posy[c2]>1&&y+posy[c2]<w)
        {
          int tmp=chk(x+posx[c],y+posy[c2]);

          rem[tmp]--;
          rem[tmp+1]++;
        }
      }
      data[x][y];
    }
  }
  for(int c=0;c<10;c++)
  printf("%lld\n",rem[c]);
}
