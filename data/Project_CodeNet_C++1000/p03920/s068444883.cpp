#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
#include<map>
#include<set>
#include<climits>
#include<vector>

#define INF (1<<29)
#define all(c) (c).begin(),(c).end()

using namespace std;

typedef long long ll;
typedef pair<int,int> pii;

vector<int>res;
bool check(int n,int mx){
  for(int i=mx;i>0;i--){
    if(n>=i){
      n-=i;
      res.push_back(i);
    }
  }
  return n==0;
}

int main(void){

  int n;
  cin >> n;

  int l=0,r=2*n;
  vector<int>ans;
  while(r-l>1){
    res.clear();
    int m = (r+l)/2;
    if(check(n,m)){
      r=m;
      ans=res;
    }
    else l=m;
  }
  int size = ans.size();
  for(int i=size-1;i>=0;i--)
    cout << ans[i] << endl;
  
  return 0;
}
