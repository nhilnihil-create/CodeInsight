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
typedef pair<int,int> P;
#define rep(i,n) for(int i=0;i<(n);i++)
#define all(a) (a).begin(),(a).end()

int main(){
  string S;
  cin>>S;
  int K;
  cin>>K;
  rep(i,S.size()){
    if(S[i]=='a') continue;
    int X='z'+1-S[i];
    if(K>=X){
      S[i]='a';
      K-=X;
    }
  }
  S[S.size()-1]='a'+(S[S.size()-1]-'a'+K)%26;
  cout<<S<<endl;
}