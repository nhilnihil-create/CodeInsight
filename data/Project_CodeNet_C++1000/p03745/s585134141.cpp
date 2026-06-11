#include <iostream>
#include <vector>
using namespace std;

long long greater_num(int i, long long n, vector<long long int> &a){
  for(int k=i; k<n; k++){
     if(a[k] > a[k+1]) return k;
  }//for
  return n-1;
}//greater_num

long long less_num(int i, long long n, vector<long long int> &a){
  for(int k=i; k<n; k++){
     if(a[k] < a[k+1]) return k;
  }//for
  return n-1;
}//greater_num

int main(void){
  long long N;
  cin >> N;
  vector<long long int> a(N);
  for(int i; i<N; i++) cin >> a[i];

  int count = 0;
  for(int i=0; i<N; i++){
    if(a[i] == a[i+1]){
       continue;
    }else if(a[i] < a[i+1]){
       i = greater_num(i, N, a);
       //cout << a[i] << " " << a[i+1] << "\n";
       count++;
    }else{
       i = less_num(i, N, a);
       //cout << a[i] << " " << a[i+1] << "\n";
       count++;
    }//if
  }//for

  cout << count << "\n";
}//main
