#include <bits/stdc++.h>
using namespace std;
int main(){
  int city,road,i,counter;
  counter=0;
  cin>>city>>road;
  vector<int>vec(city);
  for(i=0;i<road*2;i++){
    int f;
    cin >> f;
    vec.at(f-1)++;
  }
  for(int x:vec)
    cout << x <<endl;
}