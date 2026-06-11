#include<bits/stdc++.h>
#define INF 1e9
#define llINF 1e18
#define MOD 1000000007
#define pb push_back
#define mp make_pair 
#define F first
#define S second
#define ll long long
#define vi vector<ll>
#define vvi vector<vi>
#define BITLE(n) (1LL<<((ll)n))
#define SHIFT_LEFT(n) (1LL<<((ll)n))
#define SUBS(s,f,t) ((s).substr((f)-1,(t)-(f)+1))
#define ALL(a) (a).begin(),(a).end()
using namespace std;

int main(){
  cin.tie(0);
  ios::sync_with_stdio(false);
  string s;cin>>s;
  if(s.front() == s.back()){
    if(s.size()%2){
      cout<<"Second"<<endl;
    }else{
      cout<<"First"<<endl;
    }
  }else{
    if(s.size()%2){
      cout<<"First"<<endl;
    }else{
      cout<<"Second"<<endl;
    }
  }
  return 0;
}
