#include <bits/stdc++.h>
#define rep(i,s,n) for(int i=s;i<n;i++)
#define pb push_back
#define all(x) (x).begin(),(x).end()
using namespace std;
using P=pair<int,int>;
using G=vector<vector<int>>;
using ll=long long;

vector<bool> seen;
vector<int> d;
vector<int> f;
#define pi 3.141592653589793


int main(int argc,char **argv){
  int n; cin>>n;
  string s,t; cin>>s>>t;

  int kyou=0;
  rep(i,0,n){
    if(s.substr(i,n)==t.substr(0,n-i)) {
      int nd=s.substr(i,n).size();
      cout<<nd+(n-nd)*2<<endl;
      return 0;
    }
  }

  cout<<2*n<<endl;
  }