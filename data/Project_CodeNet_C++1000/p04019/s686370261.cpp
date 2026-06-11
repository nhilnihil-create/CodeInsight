#include <bits/stdc++.h>
using namespace std;

int main(){
  string S;
  cin>>S;
  int N=S.size();
  map<char, int> trip;
  int tate=0;
  int yoko=0;
  for(int i=0; i<N; i++){
    trip[S.at(i)]=1;
  }
  if(trip.count('N')) tate++;
  if(trip.count('S')) tate++;;
  if(trip.count('E')) yoko++;
  if(trip.count('W')) yoko++;
  
  if(tate%2==0 && yoko%2==0) cout<<"Yes"<<endl;
  else cout<<"No"<<endl;
}
