#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <cstring>
#include <cctype>
#include <cmath>
#include <stack>
#include <queue>
#include <vector>
#include <set>
#include <map>
#include <list>
#include <stdio.h>
#include <string.h>
#include <cstdlib>
#include <math.h>
#include <bitset>
#include <iterator>
#include <iomanip>
#include <sstream>
#include <numeric>
#define INF INT_MAX
using namespace std;
int dx[5]={1,0,-1,0,0},dy[5]={0,1,0,-1,0};
long long gcd(long long a,long long b){if(a%b==0){return b;}else return gcd(b,a%b);}
long long lcm(long long a,long long b){if(a==0){return b;} return a/gcd(a,b)*b;}
#define MOD 1000000007
#define sym cout<<"---------"<<endl;
#define ll long long
#define PL pair<long long, long long>
#define mk make_pair
#define en endl
#define WHITE 1
#define BLACK 2
#define GRAY 1
#define RE return 0
#define int ll
#define P pair<int,int>

set<P> keep;
#define MAX 100005

// 上からfirst,  左からsecond
P blacks[MAX];

map<P,bool> there;
map<P,bool> searched;
int ans[10];

int solve(int H,int W){
  int ret=0;
  for(int i=H; i<H+3; i++){
    for(int j=W; j<W+3; j++){
      if(there[mk(i,j)]) ret++;
    }
  }
  return ret;
}

signed main(){
  int h,w,n;
  cin>>h>>w>>n;
  
  for(int i=0; i<n; i++){
    cin>>blacks[i].first>>blacks[i].second;
    there[blacks[i]]=true;
  }
  
  for(int i=0; i<n; i++){
    for(int j=0; j<3; j++){
      for(int k=0; k<3; k++){
        int H=blacks[i].first-j,W=blacks[i].second-k;
        if(H<=0||H>h||W<=0||W>w||H+2>h||W+2>w) continue;
        if(searched[mk(H,W)]) continue;
        searched[mk(H,W)]=true;
        int s=solve(H, W);
        ans[s]++;
      }
    }
  }
  
  int sum=accumulate(ans, ans+10, 0);
  ans[0]=(h-2)*(w-2)-sum;
  for(int i=0; i<=9; i++){
    cout<<ans[i]<<en;
  }
}

