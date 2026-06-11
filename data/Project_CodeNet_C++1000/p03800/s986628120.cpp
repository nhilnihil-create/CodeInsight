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
typedef vector< vector<int> > VVI;
typedef pair<int,int> PII;
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(a) (a).begin(),(a).end()
#define pb push_back
#define mp make_pair

int main(){
  int N;
  cin>>N;
  string S;
  cin>>S;
  int F=0;
  vector<string> SS(4);
  SS[0]+="SS";
  SS[1]+="SW";
  SS[2]+="WS";
  SS[3]+="WW";
  rep(q,4){
    F=0;
    rep(i,N-2){
      if(SS[q][i+1]=='S'){
        if(S[i+1]=='o'){
          if(SS[q][i]=='S') SS[q]+='S';
          else SS[q]+='W';
        }
        else{
          if(SS[q][i]=='S') SS[q]+='W';
          else SS[q]+='S';
        }
      }else{
        if(S[i+1]=='o'){
          if(SS[q][i]=='S') SS[q]+='W';
          else SS[q]+='S';
        }
        else{
          if(SS[q][i]=='S') SS[q]+='S';
          else SS[q]+='W';
        }
      }
    }
    if(SS[q][N-1]=='S'){
      if(S[N-1]=='o'){
        if(SS[q][0]==SS[q][N-2]) F++;
      }else{
        if(SS[q][0]!=SS[q][N-2]) F++;
      }
    }else{
      if(S[N-1]=='o'){
        if(SS[q][0]!=SS[q][N-2]) F++;
      }else{
        if(SS[q][0]==SS[q][N-2]) F++;
      }
    }
    if(SS[q][0]=='S'){
      if(S[0]=='o'){
        if(SS[q][N-1]==SS[q][1]) F++;
      }else{
        if(SS[q][N-1]!=SS[q][1]) F++;
      }
    }else{
      if(S[0]=='o'){
        if(SS[q][N-1]!=SS[q][1]) F++;
      }else{
        if(SS[q][N-1]==SS[q][1]) F++;
      }
    }
    if(F==2){
      cout<<SS[q]<<endl;
      return 0;
    }
  }
  cout<<-1<<endl;
}