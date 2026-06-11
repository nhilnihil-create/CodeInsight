#include <iostream>
using namespace std;
int assign(int, int);

int main(){
	long n;
  	cin >> n;
  	
  	long i = 0;
  	long input, a[n];
  	while(cin >> input){
    	a[i] = input;
      	i++;
    }
  
  	long sum = 1;
    int sign;
  	for(i = 0; i < n - 2; i++){
        sign = assign(a[i], a[i + 1]);
    	for(int j = i + 1; j < n - 1; j++){
            if( (sign == 1 && assign(a[j], a[j + 1]) == -1) || (sign == -1 && assign(a[j], a[j + 1]) == 1) ){
                sum++;
                i = j;
                break;
            }else if( sign == 0 ){
                sign = assign(a[j], a[j + 1]);
            }
            if( j == n - 2 ){
                cout << sum << endl;
  	            return 0;
            };
        }
    }  
  	cout << sum << endl;
  	return 0;
}

int assign(int x, int y){
    if(x > y) return -1;
    else if(x < y) return 1;
    else return 0;
}