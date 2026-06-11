#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i=0; i<(int)(n); i++)
#define all(x) x.begin(), x.end()
#define mod 1000000007
typedef long long ll;

int main(){
  int N, A, B;
  cin >> N >> A >> B;
  string str;
  cin >> str;
  int ac = 0;
  int foreignRanking = 0;
  rep(i, str.length()){
    if(str[i] == 'a'){
      if(ac < A+B){
        cout << "Yes" << endl;
        ac++;
      }else{
        cout << "No" << endl;
      }
    }else if(str[i] == 'b'){
      if(ac < A+B && foreignRanking < B){
        cout << "Yes" << endl;
        ac++;
        foreignRanking++;
      }else{
        cout << "No" << endl;
      }
    }else{
      cout << "No" << endl;
    }
  }
  return 0;
}