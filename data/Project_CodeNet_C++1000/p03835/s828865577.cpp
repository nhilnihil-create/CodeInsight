#include<bits/stdc++.h>
using namespace std;
int main(void)
{
	int K, S, t, z;
  	cin >> K >> S;
  	t = 0;
  	for(int x = 0; x <= K; x++){
    	for(int y = 0; y <= K; y++){
          z = S - x - y;
          if(0 <= z &&z <= K){
           t++;
          }
        }
    }
  cout << t << endl;
}