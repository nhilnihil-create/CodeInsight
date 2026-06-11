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
  int N, A, B; cin >> N >> A >> B;
  string S; cin >> S;

  int j=0, i=0;
  rep(k,N){
    if (S[k]=='a'){
      if (i+j<A+B) {
        cout << "Yes" << endl;
        j++;
      }
      else cout << "No" << endl;
    }
    else if (S[k]=='b'){
      if (i+j<A+B && i<B){
        cout << "Yes" << endl;
        i++;
      }
      else cout << "No" << endl;
    }
    else cout << "No" << endl;
  }


  return 0;
}
