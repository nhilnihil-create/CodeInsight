#include <iostream>
//#include <math.h>
#include <set>
#include<iomanip>
#include <algorithm>
#include <vector>
#include <string>
#include <map>
#include <utility>
#include <queue>
#define INF 1e9+7
#define rep(i,n) for(int i=0;i<n;i++)
#define NO cout<<"NO"<<endl;
#define YES cout << "YES"<<endl;
#define No cout << "No"<<endl;
#define Yes cout << "Yes"<<endl;
#define all(a) a.begin(),a.end()
#define P pair<int,int>
#define space ' '
#define pll pair<ll,ll>
using namespace std;
typedef long long int ll;
typedef unsigned long long int ull;

//(int)'a'は97 (int)'A'は65 (int)'1'は49
//おまじない

const int maxn = 100;

int main(){

  int h,w,n;
  int a[maxn*maxn];
  int grid[maxn+10][maxn+10]={0};

  cin >> h>>w>>n;
  rep(i,n)cin >> a[i];

  int pos = 0;
  rep(i,h){
    if(i%2==0){
      for(int j=0;j<w;j++){
        if(a[pos]==0)pos++;
        grid[i][j]=pos+1;
        a[pos]--;
      }
    }else{
      for(int j=w-1;j>=0;j--){
        if(a[pos]==0)pos++;
        grid[i][j]=pos+1;
        a[pos]--;
      }
    }
  }

  rep(i,h){
    rep(j,w){
      if(j==w-1)cout << grid[i][j];
      else cout << grid[i][j]<<' ';
    }
    cout << endl;
  }

  return 0;
}
