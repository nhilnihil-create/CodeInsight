#include <bits/stdc++.h>
using namespace std;
 
int main() {
  int N,M;
  cin >> N >> M;
  vector<int> vec(2);
  vector<int> c(N,0);
 for(int i=0;i<M;i++){
     cin >> vec.at(0)>>vec.at(1);
     for(int j=1;j<=N;j++){
        if(vec.at(0)==j||vec.at(1)==j){
            c.at(j-1)++;}
            
     }
 }
 for(int k=0;k<N;k++){
     cout << c.at(k)<<endl;
 }
}