#include <bits/stdc++.h>
using namespace std;

int main() {
  int H;
  cin >> H;
  vector<int> vec(H,0);

  for (int i=0; i<H; i++){
    int a;
    cin>>a;

    vec.at(i)+=a; 
  }
  int x=0;
  int s=0;
  if (vec.at(0)==2){
      x++;
      cout<<x<<endl;
  }
  else{
      for (int i=0; i<H; i++){
              if(vec.at(s)==2){
              i++;
              cout<<i<<endl;
              s=2;
              break;
              }
              else
              s = vec.at(s)-1;
              
          }
          if (s!=2)
          cout<<-1<<endl;
  }
}
