#include <bits/stdc++.h>
using namespace std;

int main(){
  int N; cin >> N;
  multiset<int> a;
  for(int i=0; i<N; i++){
    int tmp; cin >> tmp;
    a.insert(tmp);
  }
  int f=*(a.begin());
  int b=*(--a.end());
  if(f==b){
    if(f==N-1||f<=N/2) cout << "Yes" << endl;
    else cout << "No" << endl;
  }else if(f+1==b){
    int c=a.count(f);
    if(N-c>=2){
      if(b>=c+1&&b<=c+(N-c)/2){
        cout << "Yes" << endl;
      }else{
        cout << "No" << endl;
      }
    }else{
      cout << "No" << endl;
    }
  }else{
    cout << "No" << endl;
  }
}