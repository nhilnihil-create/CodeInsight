#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
#include <stack>
#include <queue>
#include <set>
#include <map>
#include <iomanip>
using namespace std;
typedef long long ll;
typedef vector<int> VI;
typedef vector<ll> VL;
typedef vector< vector<int> > VVI;
typedef vector< vector<int> > VVL;
typedef pair<int,int> PII;
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(a) (a).begin(),(a).end()
#define pb push_back
#define mp make_pair
#define ub upper_bound
#define lb lower_bound

int main(){
  ll A,B;
  cin>>A>>B;
  if(A==0){
    if(B>=0) cout<<B<<endl;
    else cout<<-B+1<<endl;
  }else if(B==0){
    if(A>=0) cout<<A+1<<endl;
    else cout<<-A<<endl;
  }else if((A>=0&&B>=0)||(A<=0&&B<=0)){
    if(B>=A) cout<<B-A<<endl;
    else cout<<A-B+2<<endl;
  }else{
    if((B>=0&&B>=-A)||(B<=0&&A>=-B)) cout<<B+A+1<<endl;
    else cout<<-B-A+1<<endl;
  }
}