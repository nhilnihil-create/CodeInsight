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
  string s,t;
  cin>>s>>t;
  if(s.size()>t.size())
    cout<<"GREATER"<<endl;
  else if(s.size()<t.size())
    cout<<"LESS"<<endl;
  else{
    if(s==t) cout<<"EQUAL"<<endl;
    else if(s>t) cout<<"GREATER"<<endl;
    else cout<<"LESS"<<endl;
  }
}