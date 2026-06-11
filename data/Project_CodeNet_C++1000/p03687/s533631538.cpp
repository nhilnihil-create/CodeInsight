#include <bits/stdc++.h>
#include <stdlib.h>
#include <string>
#include <iostream>
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

bool detect(string s, char target){
  bool flag = false;
  rep(i, s.size()){
    if (s[i] != target){
      flag = true;
      break;
    }
  }
  return flag;
}

int main(){
  string s; cin >> s;
  map <char, int> mojisuu;
  rep(i, s.size()){
    mojisuu[s[i]]++;
  }
  char target;
  int ans = 500;
  string alphabet = "abcdefghijklmnopqrstuvwxyz";
  rep(alpha, 26){
    target = alphabet[alpha];
    int ans_temp = 0;
    string s_temp = s;
  	while (detect(s_temp, target) && s_temp.size() > 1){
      ans_temp++;
      string s_next;
      rep(i, s_temp.size()-1){
        if (s_temp[i] == target || s_temp[i+1] == target) s_next.push_back(target);
        else s_next.push_back(s_temp[i]);
      }
      swap(s_temp, s_next);
    }
    ans = min(ans, ans_temp);
  }
  cout << ans << endl;
}  