#include <bits/stdc++.h>
 
using namespace std;
typedef long long ll;
typedef vector<int> VI;
ll mm=1000000000;ll MM=mm+7;
#define rep(i, n) for(int i=0;i<n;i++)
#define PI 3.141592653589793

int main(){
  int n,m;
  cin >> n >> m;
  int d=n-m;
  vector<vector<char>> a(n,vector<char>(n));
  vector<vector<char>> b(m,vector<char>(m));
  rep(i,n){
      rep(j,n){
          cin >> a.at(i).at(j);
      }
  }
  rep(i,m){
      rep(j,m){
          cin >> b.at(i).at(j);    
      }
  }
  bool e=false;
  rep(k,d+1){
      rep(l,d+1){
          bool c=true;
          rep(i,m){
              rep(j,m){
                  if(a.at(k+i).at(l+j)!=b.at(i).at(j)){
                      c=false;
                      break;
                  }
              }
              if(c==false)break;
          }
        if(c){
            e=true;
            break;
        }
      }
      if(e)break;
  }
    if(e)cout << "Yes" << endl;
    else cout << "No" << endl;
}

