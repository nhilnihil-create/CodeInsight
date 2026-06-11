#include <bits/stdc++.h>
#include <stdlib.h>
#include <string>
#include <algorithm>
#include <map>
using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<vll> vvll;
typedef vector<string> vs;
typedef vector<bool> vb;
typedef pair<int, int> P;

#define rep(i, n) for(int i = 0; i < (int)(n); i++)
#define all(x) (x).begin(),(x).end()
#define rall(x) (x).rbegin(),(x).rend()

int main(){
  int N, A, B;
  cin >> N >> A >> B;
  string S;
  cin >> S;
  int AB = A + B;
  int num_AB = 0;
  int num_B = 0;
  rep(i, N){
    if (S[i] == 'a'){
      num_AB++;
      if (num_AB <= AB){
        cout << "Yes" << endl;
      }else{cout << "No" << endl;}
    }
    else if (S[i] == 'b'){
      num_B++;
      if (num_AB <= AB-1 && num_B <= B){
        num_AB++;
        cout << "Yes" << endl;
      }else{cout << "No" << endl;}
    }
    else{cout << "No" << endl;}
  }
}  