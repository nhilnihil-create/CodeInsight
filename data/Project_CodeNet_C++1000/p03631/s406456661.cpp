#include <bits/stdc++.h>
using namespace std;
#define rep(i,n) for(int i=0;i<n;i++)
#define rep1(i,n) for(int i=1;i<n+1;i++)
#define sort(A) sort(A.begin(),A.end())
#define reverse(A) reverse(A.begin(),A.end())
typedef long long ll;
typedef pair<int,int> P;

int main(){
  string T;
  cin >>T;
  rep(i,T.size()){
    if(T[i] != T[T.size()-1-i]){
      cout << "No" << endl;
      return 0;
    }
  }
  cout << "Yes" << endl;
}