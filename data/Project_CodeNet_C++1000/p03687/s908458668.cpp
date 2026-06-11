 #include <bits/stdc++.h>
 using namespace std;
 #define rep(i,N) for(int i=0;i<int(N);++i)
 using ll = long long;
 const int INF = 2147483647;
 const ll MOD = 1000000007;
 // const ll INF = 1000000000000000000LL;

bool sequence(string s){
  bool ok = true;
  char ch = s[0];
  for(int i=1;i<s.size();i++){
    if(s[i]!=ch)
      ok = false;
  }
  return ok;
} 

int main() {
  string input_s,s;
  cin >> input_s;
  int ans = INF;
  if(sequence(input_s)){
    cout << 0 << endl;
    return 0;
  }

  rep(i,26){
    s = input_s;
    char ch = i + 'a';
    int cur = 0;
    while(s.size()){
      rep(j,s.size()-1){
        if(s[j+1]==ch)
          s[j] = ch;
      }
      s.pop_back();
      cur++;
      if(sequence(s)) break;
    }
    ans = min(ans,cur);
  }
  cout << ans << endl;
	return 0;
}
