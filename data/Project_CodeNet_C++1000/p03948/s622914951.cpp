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
#define INF 2000000000
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

#define MAX 100005
int a[MAX];

// 利益の最大値 first  配列の場所 second
vector<P> max_dif;

signed main(){
  int n,t; cin>>n>>t;
  for(int i=0; i<n; i++) cin>>a[i];
  
  max_dif.push_back(mk(-1,-1));
  int minl=INF;
  for(int i=0; i<n; i++){
    minl=min(minl,a[i]);
    int d=a[i]-minl;
    if(d==max_dif[0].first) max_dif.push_back(mk(d,i));
    else if(d>max_dif[0].first){
      max_dif.clear();
      max_dif.push_back(mk(d,i));
    }
  }
  
  cout<<max_dif.size()<<en;
}

