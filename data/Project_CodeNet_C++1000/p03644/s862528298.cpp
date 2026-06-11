#include<bits/stdc++.h>
using namespace std;
int main()
{
	int N;
  	cin >> N;
  	for(int i = 0; i <= 7; i++){
    	if(!(N >= pow(2, i))){
          cout << pow(2, i - 1) << endl;
        	break;
        } 
    }
  return 0;
}
