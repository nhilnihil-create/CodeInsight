#include <bits/stdc++.h>
using namespace std;

int main() {
  int H,W;
  cin >> H>>W;
  vector<int> vec(H,0);

  for (int i=0; i<W; i++){

    int a,c;
    cin>>a>>c;

    vec.at(a-1)++; 
    vec.at(c-1)++;

  }
  for (int i=0; i<H; i++){
    cout<<vec.at(i)<<endl;
  }

}
   
