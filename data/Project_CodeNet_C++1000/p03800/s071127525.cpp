#include<bits/stdc++.h>

using namespace std;
using ll = long long;
using ull = unsigned long long;
using P = pair<int,int>;
#define rep(i,n) for(ll i = 0;i < (ll)n;i++)
#define ALL(x) (x).begin(),(x).end()
#define MOD 1000000007


int n;
string s;
string make(string t){
  for(int i = 1;i < n-1;i++){
    if(t[i] == 'S'){
      if(s[i] == 'o')t += t[i-1];
      else t += (t[i-1] == 'S' ? 'W' : 'S');
    }else{
      if(s[i] == 'o')t += (t[i-1] == 'S' ? 'W' : 'S');
      else t += t[i-1];
    }
  }
  return t;
}
bool check(string t,bool is){
  if(is){
    if(t[0] == 'S' && s[0] == 'o')return t[1] == t.back() ? true : false;
    else if(t[0] == 'S' && s[0] == 'x')return t[1] == t.back() ? false : true;
    else if(t[0] == 'W' && s[0] == 'o')return t[1] == t.back() ? false : true;
    else return t[1] == t.back() ? true : false;
  }else{
    if(t.back() == 'S' && s.back() == 'o')return t[0] == t[n-2] ? true : false;
    else if(t.back() == 'S' && s.back() == 'x')return t[0] == t[n-2] ? false : true;
    else if(t.back() == 'W' && s.back() == 'o')return t[0] == t[n-2] ? false : true;
    else return t[0] == t[n-2] ? true : false;
  }
}

int main(){
  
  cin >> n >> s;
  {
    string t = make("SS");
    if(check(t,true) && check(t,false)){
      cout << t << endl;
      return 0;
    }
    
  }
  {
    string t = make("SW");
    if(check(t,true) && check(t,false)){
      cout << t << endl;
      return 0;
    }
    
  }
  {
    string t = make("WW");
    if(check(t,true) && check(t,false)){
      cout << t << endl;
      return 0;
    }
    
  }
  {
    string t = make("WS");
    if(check(t,true) && check(t,false)){
      cout << t << endl;
      return 0;
    }

  }
  cout << -1 << endl;
  


  return 0;
}