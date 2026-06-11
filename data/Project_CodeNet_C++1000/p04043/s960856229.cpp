#include <iostream>
#include <vector>
#include <algorithm>
#include <list>
#include <iomanip>
#include <string>
#include <cctype>
#include <cstdio>
#include <cmath>

using namespace std;

int main() {
  vector<int> word(3);
  int five=0,seven=0;
  for(int i=0;i<3;i++)
    cin>>word[i];
  for(int i=0;i<3;i++){
    if(word[i]==5)
      five++;
    else if(word[i]==7)
      seven++;
  }
  if(five==2&&seven==1)
    cout<<"YES"<<endl;
  else
    cout<<"NO"<<endl;
}