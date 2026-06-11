#include<iostream>
#include<iomanip>
#include<cmath>
#include<string>
#include<cstring>
#include<vector>
#include<list>
#include<algorithm>
#include<map>
#include<set>
#include<queue>
#include<stack>
using namespace std;
typedef long long ll;
#define fi first
#define se second
#define mp make_pair
#define mt make_tuple
#define pqueue priority_queue
const int inf=1e9+7;
const ll mod=1e9+7;
const ll mod1=998244353;
const ll big=1e18;
const double PI=2*asin(1);

int main() {
  string A, B;
  cin>>A>>B;
  if(A.size()>B.size()) {
    cout<<"GREATER"<<endl;
    return 0;
  }
  if(A.size()<B.size()) {
    cout<<"LESS"<<endl;
    return 0;
  }
  bool equ = true, a=false;
  for(int i=0;i<A.size();++i) {
    if(A[i]<B[i]) {
      equ = false;
      a = false;
      break;
    }
    else if(A[i]>B[i]) {
      equ = false;
      a = true;
      break;
    }
  }
  if(equ) cout<<"EQUAL"<<endl;
  else if(a) cout<<"GREATER"<<endl;
  else cout<<"LESS"<<endl;
}
