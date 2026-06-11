#include<iostream>
#include<vector>
#include<algorithm>
#include<iomanip>

#define PI 3.141592653589793238
#define INF 1050000000

using namespace std;



//cout << fixed << setprecision(15) << << endl;
//cout << << endl;

int main() {

	int N;

	cin >> N;

	int a,b,c,K;
  
    a = N%10;
    b = (N/10)%10;
    c = N/100;
  
    K = a*100+b*10+c;
  
    if(K==N){
      cout << "Yes" <<endl;
    }else{
      cout << "No" <<endl;
    }


	return 0;
}
