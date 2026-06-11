#include <iostream>
#define mx 1000000000
using namespace std;
long long mat[510][510];
int main(){
	int a,b,c,d,i,j;
	long long sum=0;
	cin >> a >> b >> c >> d;
	if(a%c==0 && b%d==0){
		cout << "No" << endl;
		return 0;
	}
	for(i=0;i<a;i++){
		for(j=0;j<b;j++){
			if(i%c==0 && j%d==0){
				mat[i][j] = mx-1;
			}else if(i%c==c-1 && j%d==d-1){
				mat[i][j] = -mx;
			}else{
				mat[i][j] = 0;
			}
			sum += mat[i][j];
		}
	}
	if(sum>0){
		cout << "Yes" << endl;
		for(i=0;i<a;i++){
			for(j=0;j<b;j++){
				cout << mat[i][j] << " " ;
			}
			cout << endl;
		}
	}else{
		cout  << "No" << endl;
	}
}