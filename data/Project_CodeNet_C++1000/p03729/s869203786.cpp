#include<bits/stdc++.h>
using namespace std;
#define all(v) v.begin(), v.end()
using in = int64_t;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define REP(i,a,b) for(int i=(int)(a);i<(int)(b);i++)
#define Yes cout<<"Yes"<<endl 
#define No cout<<"No"<<endl
#define yes cout<<"yes"<<endl 
#define no cout<<"no"<<endl
#define vec(a,y,x)  vector<vector<char>> a (y,vector<char>(x))
const vector<int> dx={1,0,-1,0};
const vector<int> dy={0,1,0,-1};

int main(){
  string a,b,c;
  cin>>a>>b>>c;
  int pa=a.size();
  int pb=b.size();
  int pc=c.size();
  if(a.at(pa-1)==b.at(0) && b.at(pb-1)==c.at(0))
    cout<<"YES"<<endl;
  else
    cout<<"NO"<<endl;
}