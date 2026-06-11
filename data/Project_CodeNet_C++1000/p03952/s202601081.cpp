#include<bits/stdc++.h>
using namespace std;

vector<int> vec(9);
 
int calc_med(int n, int x){
  if(n == 0){
    return vec[x-1];
  }
  else{
    int a = calc_med(n-1,x-1);
    int b = calc_med(n-1,x);
    int c = calc_med(n-1,x+1);
    return a+b+c - max({a,b,c}) - min({a,b,c});
  }
}

int main(){
  int N, x;
  cin >> N >> x;
  /*for(int i=0; i<2*N-1; i++){
    vec[i] = i+1;
  }
  vector<int> cnt(2*N-1);
  do{
    for(int i=0; i<2*N-1; i++){
      cout << vec[i] << " ";
    }
    if(cnt.at(calc_med(N-1,N)-1) == 0){
      for(int i=0; i<2*N-1; i++){
        cout << vec[i] << " ";
      }
      cout << "MED = " << calc_med(N-1,N) << endl;
    }
    cnt.at(calc_med(N-1,N)-1)++;
  }while(next_permutation(vec.begin(),vec.end()));
  for(int i=0; i<2*N-1; i++){
    cout << cnt[i] << endl;
  }*/
  
  if(x == 1 || x == 2*N-1){
    cout << "No" << endl;
  }
  else{
    cout << "Yes" << endl;
    deque<int> D;
    D.push_back(x);
    if(x == N){
      for(int i=N-1; i>0; i--){
        D.push_front(i);
      }
      for(int i=N+1; i<=2*N-1; i++){
        D.push_back(i);
      }
    }
    else if(x < N){
      D.push_front(x-1);
      for(int i=N; i>0; i--){
        if(i == x || i == x-1){
          continue;
        }
        D.push_front(i);
      }
      for(int i=N+1; i<=2*N-1; i++){
        D.push_back(i);
      }
    }
    else{
      D.push_back(x+1);
      for(int i=N-1; i>0; i--){
        D.push_front(i);
      }
      for(int i=N; i<=2*N-1; i++){
        if(i == x+1 || i == x){
          continue;
        }
        D.push_back(i);
      }
    }
    while(D.size()){
      cout << D.front() << endl;
      D.pop_front();
    }
  }
        
}