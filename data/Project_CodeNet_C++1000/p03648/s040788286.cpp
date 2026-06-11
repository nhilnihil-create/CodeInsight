#include <bits/stdc++.h>
using namespace std;

#define max(a,b) ((a)>(b)?(a):(b))
#define min(a,b) ((a)<(b)?(a):(b))

typedef long long LL;

int main(){
  LL k;
  cin >> k;
  if(k==0){
    cout << 2 << endl;
    cout << "1 1" << endl;
    return 0;
  }
  if(k==1){
    cout << 3 << endl;
    cout << "1 0 3" << endl;
    return 0;
  }
  if(k<=50){
    cout << k << endl;
    cout << k;
    for(int i=1;i<k;i++){
      cout << " " << k;
    }
    cout << endl;
    return 0;
  }
  cout << 50 << endl;
  if(k%50){
    for(int i=0;i<49;i++){
      if(i<k%50)  cout << 50+(k/50)  << " ";
      else  cout << (50-1)+(k/50)-k%50  << " ";
    }
    cout << 50+k/50-1-k%50  << endl;
  }else{
    for(int i=0;i<49;i++){
      cout << (50-1)+(k/50)  << " ";
    }
    cout << 50+k/50-1  << endl;
  }
  return 0;
}
