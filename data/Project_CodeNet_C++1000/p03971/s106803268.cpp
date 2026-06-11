#include <bits/stdc++.h>
using namespace std;

int main(){
  int N,Qdom,Qabr;
  string ranking;
  cin >> N >> Qdom >> Qabr >> ranking;
  const int Qtot= Qdom+ Qabr;

  int q_tot= 0;
  int q_abr= 0;
  for(auto player:ranking){
    if(player=='a'){
      if(q_tot < Qtot){
        cout << "Yes" << endl;
        q_tot++;
      }
      else{
        cout << "No" << endl;
      }
    }
    else if(player=='b'){
      if(q_tot < Qtot && q_abr < Qabr){
        cout << "Yes" << endl;
        q_tot++;
        q_abr++;
      }
      else{
        cout << "No" << endl;
      }
    }
    else{
      cout << "No" << endl;
    }
  }
}