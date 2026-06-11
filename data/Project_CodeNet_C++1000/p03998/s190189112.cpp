#define _GLIBCXX_DEBUG
#include<bits/stdc++.h>
#define rep(i,n) for (int i = 0;i < (n);i++)
#define all(v) v.begin(),v.end()
#define dec(n) cout << fixed << setprecision(n);
#define large "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
#define small "abcdefghijklmnopqrstuvwxyz"
using namespace std;
using ll = long long;
using P = pair<ll,ll>;
using vl = vector<ll>;
using vvl = vector<vl>;

ll gcd(ll a,ll b){
  if(b == 0) return a;
  return gcd(b , a % b);
}

ll mod(ll a){
  return (a % 1000000007);
}

ll lcm(ll a,ll b){
  return (a*b)/gcd(a,b);
}



int main(){
  string sa,sb,sc; cin >> sa >> sb >> sc;
  ll nowa,nowb,nowc; nowa = 0; nowb = 0; nowc = 0;
  char nowturn = 'a'; char ans = '0';
  
  while(ans == '0'){
    

    
    if(nowturn == 'a'){
      if(nowa == sa.size()){
        ans = 'A';
        break;
      }
      
      nowturn = sa[nowa];
      nowa++;
      continue;
    }
    
    else if(nowturn == 'b'){ 
      if(nowb == sb.size()){
        ans = 'B';
        break;
      }
      
      nowturn = sb[nowb];
      nowb++;
      continue;
      
     
    }
    
    else{ 
      
      if(nowc == sc.size()){
        ans = 'C';
        break;
      }
      
      nowturn = sc[nowc];
      nowc++;
      continue;
      
     
    }
    
  }
  
  
  cout << ans << endl;
}