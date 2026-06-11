#include <bits/stdc++.h>
using namespace std;

int main() {
  int N,M;
  cin >> N >> M ;
  
  vector< int > vec(N*M);
  
       for (int i = 0; i < (M*2) ;i++){
      			cin >> vec.at(i);
            }
  
		for (int ii = 0; ii < N; ii++) {
            int count = 0;
            for (int i = 0; i < (M*2) ;i++){
     			 if ( vec.at(i) == ( ii + 1 )){
            			 count ++;
       				 } 
            }
             cout << count << endl;
	}
}