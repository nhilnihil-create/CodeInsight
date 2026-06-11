#include <bits/stdc++.h>

using namespace std;

int a[15000][15000];
int n,m,k;

void dd(int x,int y,int t,int d)
{
          for(int i=0;i<t;i++)
          {
                    int posx=x+i*2;
                    int posy=y;
                    for(int j=0;j<t-i;j++)
                    {
                              a[posx+j][posy+j]=d;
                              a[posx+j][posy-j]=d;
                    }
          }
}

int d(int x1,int y1,int x2,int y2)
{
          return abs(x1-x2)+abs(y1-y2);
}

int main()
{
          ios_base::sync_with_stdio(0);
          cin>>n>>m>>k;
          if(k%2)
          {
                    for(int i=0;i<n;i++)
                              for(int j=0;j<m;j++)
                                        a[i][j]=(i+j)%2;
                    for(int i=0;i<n;i++)
                    {
                              for(int j=0;j<m;j++)
                                        if(a[i][j])
                                                  cout<<"Y";
                                        else
                                                  cout<<"G";
                              cout<<endl;
                    }
                    return 0;
          }
          int pos=0;
          int kilk=k/2;

          for(int i=550;i<550+2500;i+=k)
                    for(int j=550;j<550+2500;j+=k)
                    {
                              int x=(i-550)/k;
                              int y=(j-550)/k;
                              if(x%2==0 && y%2==0)
                                        dd(i,j,k/2,1);
                              if(x%2==1 && y%2==0)
                                        dd(i,j,k/2,3);
                              if(x%2==0 && y%2==1)
                                        dd(i,j,k/2,3);
                              if(x%2==1 && y%2==1)
                                        dd(i,j,k/2,1);
                    }

          for(int i=550+k/2;i<550+2500;i+=k)
                    for(int j=550+k/2;j<550+2500;j+=k)
                    {
                              int x=(i-550)/k;
                              int y=(j-550)/k;
                              if(x%2==0 && y%2==0)
                                        dd(i,j,k/2,2);
                              if(x%2==1 && y%2==0)
                                        dd(i,j,k/2,4);
                              if(x%2==0 && y%2==1)
                                        dd(i,j,k/2,4);
                              if(x%2==1 && y%2==1)
                                        dd(i,j,k/2,2);
                    }

          for(int i=550;i<550+2500;i+=k)
                    for(int j=550;j<550+2500;j+=k)
                    {
                              int x=(i-550)/k;
                              int y=(j-550)/k;
                              if(x%2==0 && y%2==0)
                                        dd(i+1,j,k/2,1);
                              if(x%2==1 && y%2==0)
                                        dd(i+1,j,k/2,3);
                              if(x%2==0 && y%2==1)
                                        dd(i+1,j,k/2,3);
                              if(x%2==1 && y%2==1)
                                        dd(i+1,j,k/2,1);
                    }

          for(int i=550+k/2;i<550+2500;i+=k)
                    for(int j=550+k/2;j<550+2500;j+=k)
                    {
                              int x=(i-550)/k;
                              int y=(j-550)/k;
                              if(x%2==0 && y%2==0)
                                        dd(i+1,j,k/2,2);
                              if(x%2==1 && y%2==0)
                                        dd(i+1,j,k/2,4);
                              if(x%2==0 && y%2==1)
                                        dd(i+1,j,k/2,4);
                              if(x%2==1 && y%2==1)
                                        dd(i+1,j,k/2,2);
                    }


          for(int i=2000;i<2000+n;i++)
          {
                    for(int j=2000;j<2000+m;j++)
                    {
                              if(a[i][j]==1)
                                        cout<<'Y';
                              if(a[i][j]==2)
                                        cout<<'R';
                              if(a[i][j]==3)
                                        cout<<'G';
                              if(a[i][j]==4)
                                        cout<<'B';
                    }
                    cout<<endl;
          }

}
