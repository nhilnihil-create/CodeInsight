#include <bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin >> S;
  long long ans = 0;
  for(int s = 0;s < (1 <<(S.size()-1));s++){
  	string conn = "";
    conn += S[0];
    for(int i = 0;i < S.size()-1;i++){
      if(s & (1 << i)) conn += "+";
      conn += S[i + 1];
    }
    long long sum = 0;
    int pos = 0;
    while(conn.find("+",pos) != string::npos){
      int nextpos = conn.find("+", pos);
      sum += stoll(conn.substr(pos, nextpos - pos));
      pos = nextpos+1;
    }
    sum += stoll(conn.substr(pos));
    ans += sum;
  }
  cout << ans << endl;
}