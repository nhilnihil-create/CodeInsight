#include<bits/stdc++.h>
using namespace std;

int main(void){
  int h, w;
  cin >> h >> w;
  
  vector<char> moji(h*w);
  for( int i=0 ; i < h*w ; i++ ){
    cin >> moji.at(i);
  }
  
  vector<char> huti((h+2)*(w+2)-h*w, '#');
  
  int n = 0, m = 0;
  for( int i=0 ; i < h+2 ; i++ ){
    for( int j=0 ; j < w+2 ; j++ ){
      if( i == 0 || i == h+1 ){
        cout << huti.at(n);
        n++;
      }
      else if( j%(w+2) == 0 || j%(w+2) == (w+2)-1 ){
        cout << huti.at(n);
        n++;
      }
      else{
        cout << moji.at(m);
        m++;
      }
      if( j%(w+2) == (w+2)-1 )  cout << endl;
    }
  }
}