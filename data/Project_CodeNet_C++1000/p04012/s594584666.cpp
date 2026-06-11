#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<(int)(n);i++)
#define all(v) v.begin(),v.end()
#define rall(v) v.rbegin(),v.rend()
typedef long long ll;
#define _GLIBCXX_DEBUG
typedef vector<int> vec;
typedef vector<ll> lvec;
typedef vector<char> cvec;
typedef vector<double> dvec;
typedef pair<ll, ll> LP;
typedef tuple<ll, ll, ll> LT;
typedef pair<int, int> P;
typedef tuple<int, int, int> T;
#define fs first
#define sc second
int main()	{
  string s;
  cin>>s;
  vector<int>d(26);
  rep(i,s.size()){
    d[s[i]-'a']++;
  }
  rep(i,26){
    if(d[i]%2){
      cout<<"No"<<endl;
      return 0;
    }
  }
  cout<<"Yes"<<endl;
}
    