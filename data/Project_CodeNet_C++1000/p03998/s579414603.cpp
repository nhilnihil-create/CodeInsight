#include <iostream>

using namespace std;

int main(){
  string a,b,c;
  cin >> a >> b >> c;
  int d,e,f;
  d = a.size();
  e = b.size();
  f = c.size();
  int g = 0,h = 0,j = 0;
  char top = 'a';
  char ans;
  for(int i = 0;i<400;i++){
    if(top=='a'){
      if(g==d){
        ans = 'A';
        break;
      }
      top = a.at(g);
      g++;
    }
    else if(top=='b'){
      if(h==e){
        ans = 'B';
        break;
      }
      top = b.at(h);
      h++;
    }
    else{
      if(j==f){
        ans = 'C';
        break;
      }
      top = c.at(j);
      j++;
    }
  }
  cout << ans << endl;
}