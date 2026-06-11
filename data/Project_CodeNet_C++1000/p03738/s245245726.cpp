#include<bits/stdc++.h>
#include<cctype>
using namespace std;
#define rep(i,n) for (int i=0;i<(n);i++)
#define all(v) (v).begin(),(v).end()
typedef long long int ll;
#define pi 3.1415926535897932384
#define E9 1000000000
#define eps 1e-4
#define pii pair<int,int>


int main(){
  string A, B; cin >> A >> B;
  if (A==B) {
    cout << "EQUAL" << endl;
    return 0;
  }

  if (A.size()>B.size()) cout << "GREATER" << endl;
  else if (A.size()<B.size()) cout << "LESS" << endl;
  else{
    rep(i,A.size()){
      if (A[i]>B[i]){
        cout << "GREATER" << endl;
        return 0;
      }
      else if (A[i]<B[i]){
        cout << "LESS" << endl;
        return 0;
      }
      else continue;      
    }
  }
  


  // cout << fixed << setprecision(6);
  return 0;
}
