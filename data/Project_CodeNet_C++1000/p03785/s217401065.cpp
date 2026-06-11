#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
using ll = long long;
using ld = long double;
const ll ATCODER_AMARI = 1000000007; //10^9 + 7
const ll INF = 10000000000000;
//階乗できるよ
ll kaizyo(ll k){
  ll sum = 1;
  for(int i = 1 ; i < k + 1; i++) {
    sum *= i;
    sum = sum % ATCODER_AMARI;
  }
  return sum;
}

int main() {
  ll n,c,k; cin >> n >> c >> k;
  vector<ll> t(n);
  rep(i,n) cin >> t[i];
  sort(t.begin(),t.end());
  ll current_first_number = 0;
  ll current_first_time = t.at(0);
  ll current_limit = t.at(0) + k;
  // ll wait_people = 0;
  ll bus = 0;

  rep(i,n) {
    if(t.at(i) > current_limit) {
      ll wait_people = (i - 1) - current_first_number + 1;
      if(wait_people <= c) {
        bus++;
        current_first_number = i;
        current_limit = t.at(i) + k;
      //  cout << current_first_number << endl;
        i--;
        continue;
      }
      else if(wait_people > c){
        bus++;
        current_first_number = current_first_number + c;
        current_limit = t.at(current_first_number) + k;
      //    cout << current_first_number << endl;
        i--;
        continue;
      }
    }
    else if(i == n - 1) {
      ll wait_people_n = i - current_first_number + 1;
      if(wait_people_n <= c){
        bus++;
        break;
      }
      else if(wait_people_n > c){
        ll syo = wait_people_n / c;
        ll amari = wait_people_n % c;
        if(amari == 0) {
          bus += syo;
        }
        else{
          bus += syo + 1;
        }
      }
    }
    
  }

  cout << bus << endl;
}

