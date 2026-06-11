#include <iostream>
#include <string>
#include <vector>
#include <set>
#include <algorithm>
#include <cctype>
#include <cmath>
#include <queue>
#include <map>
#include <numeric>
#include <unordered_map>
#include <iomanip>
#include <functional>
#include <bitset>
#include <complex>
#include <stack>



#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define rrep(i, n) for(int i = (int)(n-1); i >= 0; i--)
#define repi(i,a,b) for(int i=int(a);i<int(b);i++)
#define all(x) (x).begin(),(x).end()

template<class T>bool chmax(T &a, const T &b) { if (a<b) { a=b; return 1; } return 0; }
template<class T>bool chmin(T &a, const T &b) { if (b<a) { a=b; return 1; } return 0; }

typedef long long ll;

using namespace std;


int main()
{
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n;cin>>n;
  vector<int>a(n+1,0);
  rep(i,n)cin>>a[i];
  sort(all(a),greater<int>());
  int f=-1;//1:first
  rep(i,n){
  //if(a[0]==1)f=(n-1)%2;
    //if(a[i]==i+1&&a[i+1]<i+1){
      //f=0;
    //}
    if(a[i]>=i+1&&a[i+1]<i+1){//case1
      if((a[i]-1-i)%2){
        f=1;
      }
      else f=0;
      break;
    }
    if(a[i]>i+1&&a[i+1]==i+1){//case2
      //cout<<"skdfjlksd"<<endl;
      int j=i+1;
      while(a[i+1]==a[j+1])j++;
      int x=(j-(i+1))%2;
      int y=(a[i]-1-(i+1))%2;
      if(x&y){
        f=0;
      }
      else {
        f=1;
      }

      break;
    }
    if(a[i]==i+1&&a[i+1]==i+1){//case3
      int j=i+1;
      while(a[i+1]==a[j+1])j++;
      if((j-(i))%2){
        f=1;
      }
      else {
        f=0;
      }
      break;
    }
  }
  //if(f==-1)cout<<"fdSecond"<<endl;
  if(f==1){
    cout<<"First"<<endl;
  }
  else if(f==0){
    cout<<"Second"<<endl;
  }
  return 0;

}
