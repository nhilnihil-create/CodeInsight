#include<bits/stdc++.h>

using namespace std;

#define rep(i,n) for(int i=0;i<(int)n;i++)
#define INF 1e+9

int a[300][300];
int d[300][300];


void warshall_floyd(int V)
{
    rep(i,V){
        d[i][i] = 0;
    }
    rep(i,V){
        rep(j,V){
            rep(k,V){
                d[j][k] = min(d[j][k],d[j][i]+d[i][k]);
            }
        }
    }
}


int main(){

  int n;
  cin>>n;
  rep(i,n){
    rep(j,n){
      cin>>a[i][j];
      d[i][j]=a[i][j];
    }
  }
  warshall_floyd(n);
  bool flag=true;
  rep(i,n){
    if(!flag)break;
    rep(j,n){
      if(d[i][j]!=a[i][j]){flag=false;break;}
    }
  }
  if(!flag){cout<<-1<<endl;return 0;}
  long long sum = 0;
  rep(i,n){
    rep(j,n){
      flag = true;
      rep(k,n){
        if(i!=k&&j!=k&&a[i][j] == a[i][k]+a[k][j]){
          flag = false;
        }
      }
      if(flag)sum+=a[i][j];
    }
  }
  cout << sum/2 << endl;


  return 0;
}
