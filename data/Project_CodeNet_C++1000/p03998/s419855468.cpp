#include<bits/stdc++.h>
using namespace std;

int main(){
  string a,b,c;
  cin >> a >> b >> c;
  int ap=0,bp=0,cp=0;
  char next='a';
  char won;
  for(int i=0,l=a.size()+b.size()+c.size();i<l;i++){
    if(next=='a'){
      next = a.at(ap);
      ap++;
    }else if(next=='b'){
      next = b.at(bp);
      bp++;
    }else{
      next = c.at(cp);
      cp++;
    }
    if(ap==a.size()&&next=='a'){
      won='A';
      break;
    }
    if(bp==b.size()&&next=='b'){
      won='B';
      break;
    }
    if(cp==c.size()&&next=='c'){
      won='C';
      break;
    }
  }
  cout << won << endl;
}