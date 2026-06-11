#include<bits/stdc++.h>
using namespace std;
#define inf 1e9
#define ll long long 
#define M 1000000007
#define P pair<int,int>
#define FOR(i,m,n) for(int i=m;i<n;i++)
#define rep(i,n) FOR(i,0,n)
const int vx[4] = {0,1,0,-1};
const int vy[4] = {1,0,-1,0};
#define PI 3.14159265

int n;
int sum;

int main(){
  cin>>n;
  for(int i=0;;i++){
    sum+=i;
    if(sum>n){
      FOR(j,1,i+1){
        if(j==sum-n) continue;
        cout<<j<<endl;
      }
      break;
    }
  }

  return 0;
}

