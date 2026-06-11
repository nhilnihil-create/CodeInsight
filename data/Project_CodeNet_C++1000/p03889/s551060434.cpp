#include <iostream>
#include <cstdio>
#include <algorithm>
#include <string>
#include <queue>
#include <vector>
#include <set>
#include <cmath>
#include <stack>
#define FOR(i,a,b) for(int i=a;i<b;i++)
#define MA(i,j) make_pair(i,j)
#define PA pair<int,int>
#define PB push_back
#define PQ priority_queue<int>
#define PGQ priority_queue<int,vector<int>,greater<int> >
#define VE vector<int>
#define VP vector<PA>
#define YES(i) cout<<(i?"YES":"NO")<<endl
#define Yes(i) cout<<(i?"Yes":"No")<<endl
#define MOD 1000000007
#define INF 1000000007
#define PI 3.14159265358979323846
using namespace std;
//
int main(){
  string S,T;
  cin>>S;
  T=S;
  reverse(T.begin(),T.end());
  FOR(i,0,(int)T.size()){
    if(T[i]=='b'){
      T[i]='d';
    }else if(T[i]=='d'){
      T[i]='b';
    }else if(T[i]=='p'){
      T[i]='q';
    }else if(T[i]=='q'){
      T[i]='p';
    }
  }
  if(S==T){
    Yes(1);
  }else{
    Yes(0);
  }
  return 0;
}
