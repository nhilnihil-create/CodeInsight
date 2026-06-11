#include <bits/stdc++.h>
using namespace std;

int main(){
  constexpr int Nalp= 26;
  string bufS;
  cin >> bufS;
  const size_t Nlen= bufS.size();

  size_t ans= INT_MAX;
  for(int i=0; i<Nalp; i++){
    string S= bufS;
    char c= 'a'+ i;
    size_t cnt= 0;
    while(S != string(Nlen-cnt, c)){
      string Snext;
      bool exist= false;
      for(size_t l=0; l+1 < Nlen-cnt; l++){
        if(S.at(l)==c || S.at(l+1)==c){
          Snext.push_back(c);
          exist= true;
        }
        else{
          Snext.push_back(S.at(l));
        }
      }
      if(!exist){ break; }

      S= Snext;
      cnt++;
    }

    if(S==string(Nlen-cnt, c)){
      ans= min(ans, cnt);
    }
  }

  cout << ans << endl;
}