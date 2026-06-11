#include <bits/stdc++.h>
using namespace std;
#define rep(i, n) for (int i = 0; i < (int)(n); i++)
#define ll long long
int main(){
  string sa,sb,sc;
  cin >> sa >> sb >> sc;
  ll la=sa.size(),lb=sb.size(),lc=sc.size();
  char ch='a';
  ll a=0,b=0,c=0;
  while(1){
    if(ch=='a'&& a>=la){
       cout << 'A';
      break;
      return 0;
    }
    if(ch=='b'&& b>=lb){
       cout << 'B';
      break;
      return 0;
    }
    if(ch=='c'&& c>=lc){
       cout << 'C';
      break;
      return 0;
    }
    if(ch=='a'){
      ch=sa.at(a);
      a++;
    }else if(ch=='b'){
      ch=sb.at(b);
      b++;
    }else{
      ch=sc.at(c);
      c++;
    }
  }
}
    