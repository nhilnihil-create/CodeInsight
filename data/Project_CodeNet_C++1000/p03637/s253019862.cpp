#include <bits/stdc++.h>
#include <map> // pair
using namespace std;

typedef long long ll;
#define vec vector<int>
#define vecll vector<ll>
#define vpair vector<pair<int, int>>
#define vpairll vector<pair<ll, ll>>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define rep(i,n)   for(int i=(int)0; i<(int)n; i++)
#define llrep(i,n)   for(ll i=(ll)0; i<(ll)n; i++)
#define REP(i,m,n) for(int i=(int)m; i<(int)n; i++)
#define all(var)     (var).begin(), (var).end()
#define prt(var)     cout << var << endl
#define prt_dbl(i,var) cout<<fixed<<setprecision(i)<<var<<endl;
template <typename Val,typename Number>
//use ll or int for gcd
Val gcd(Val a, Val b) {
    if (b==0) return a;
    else return gcd(b, a%b);
}
//count vector and return pair (count,vector item)
template <typename Val,typename Number>
void count_vector(vector<Val>* A,vector<pair<Number,Val>>*R){
  sort(A->begin(),A->end());
  int count = 1;
  rep(i,A->size()){
    if(i<A->size()-1){
      if(A->at(i)==A->at(i+1))count++;
      else{
        R->push_back(make_pair(count,A->at(i)));
        count = 1;
      }
    }else{
      R->push_back(make_pair(count,A->at(i)));
      count = 1;
    }
  }
}

//---------------------------------------------------------------

int main(){
  int N,K;
  string ans = "No";

  cin>>N;
  int e2,e4,odd;
  e2=e4=odd=0;
  rep(i,N){
    ll A;
    cin>>A;
    if(A%4==0)e4++;
    else if(A%2==0)e2++;
    else odd++;
  }
  if(odd<e4+1){
    ans = "Yes";
  }else if(e2 == 0&&odd==e4+1){
    ans ="Yes";
  }else if(odd == 0){
    ans ="Yes";
  }


  cout<<ans<<endl;
}
