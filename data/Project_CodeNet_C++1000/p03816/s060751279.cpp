#include <iostream>
#include <cstdio>

using namespace std;
int main(void){
  int N;
  long a[100100];
  long count[100100] = {};
  cin >> N;
  
  for (int i = 0; i < N; ++i) {
  	scanf("%d", &a[i]);
    count[a[i]]++;
  }
  int num_unique = 0;
  for (int j = 0; j<=100000; j++){
    if (count[j] >=  1) {num_unique += 1;}
    
  }
 
  if (num_unique %2 == 0) {cout << num_unique -1 << endl;}
  else cout << num_unique << endl;
}
 

 