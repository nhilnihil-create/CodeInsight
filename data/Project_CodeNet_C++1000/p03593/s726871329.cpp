#include<iostream>
#include<algorithm>
#include<map>
#include<vector>
using namespace std;
typedef long long li;
#define repa(i,a,n) for(int i=(a);i<(n);i++)
#define MOD 1000000000
#define rep(i,n) for(int i=0;i<(n);i++)

#define df 0
template<class T> void print(const T& t){ cout << t << "\n"; }
template<class T, class... Ts> void print(const T& t, const Ts&... ts) { cout << t; if (sizeof...(ts)) cout << " "; print(ts...); }
// vector 型
template<class T>
std::ostream& operator<<(std::ostream& os, const vector<T>& v){
  // ここでストリームに obj を書き込みます。
  for(const T& t:v) cout << t << " ";
  return os;
}


int pow(int a, int b){
  int x=1;
  rep(i,b){
    x*=a;
  }
  return x;
}

int judge(int a,vector<int>& s,vector<int>& c){
  string t;
  while(a){
    t.push_back(a%10+'0'); a/=10;
  }
  reverse(t.begin(),t.end());
  int n=s.size();
  rep(i,n){
    if(t[s[i]]!=c[i]+'0') return 0;
  }
  
  return 1;
}

int main(){
  int h,w; cin >>h >>w;
  vector<int> v(26,0);
  rep(i,h){
    string s; cin >>s;
    if(df)print(s);
    rep(i,w){
      v[s[i]-'a']++;
    }
  }
  if(h%2>w%2)swap(h,w);
  if(w%2==0){
    rep(i,26){
      if(v[i]%4){
        print("No"); return 0;
      } 
    }
    print("Yes"); return 0;
  }
  if(h%2){
    int cnto=1,cnte=h/2+w/2;
    rep(i,26){
      if(v[i]%2){
        if(cnto) cnto--;
        else{
          print("No"); return 0;
        }
        v[i]--;
      }
      if(v[i]%4){
        if(cnte) cnte--;
        else{
          print("No"); return 0;
        }
      }
    }
    print("Yes"); return 0;
  }
  

  int cnt=h/2;
  rep(i,26){
    if(v[i]%2){
      print("No"); return 0;
    }
    if(v[i]%4){
      if(cnt) cnt--;
      else{
        print("No"); return 0;
      }
    }
  }
  print("Yes"); return 0;
  

}

