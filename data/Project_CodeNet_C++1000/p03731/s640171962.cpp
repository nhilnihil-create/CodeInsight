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
  in sum=0;
  int n;
  cin>>n;
  in T;
  cin>>T;
  vector<long> t(n);
  rep(i,n)
    cin>>t.at(i);
  
  rep(i,n-1){
    sum-=max(T-(t.at(i+1)-t.at(i)),(in)0);
  }
  cout<<sum+n*T<<endl;
}