
#include <iostream>
using namespace std;

typedef long long ll;
ll H,W,h,w,sum = 0;
ll A[501][501];
int main(){
	cin >> H >> W >> h >> w;
	if(H%h==0 && W%w==0) cout << "No" << endl;
	else{
		for(int i=1;i<=H;i++){
			for(int j=1;j<=W;j++){
				if(i%h==0 && j%w==0){
					A[i][j] = -h*w;
					sum -= h*w;
				}else{
					A[i][j] = 1;
					sum++;
				}
			}
		}
		ll t = 100;
		while(sum<=0){
			sum = 0;
			for(int i=1;i<=H;i++){
				for(int j=1;j<=W;j++){
					if(i%h==0 && j%w==0){
						A[i][j] = -t*(h*w-1)-1;
						sum += A[i][j];
					}else{
						A[i][j] = t;
						sum += A[i][j];
					}
				}
			}
			t *= 10;
		}
		cout << "Yes" << endl;
		for(int i=1;i<=H;i++){
			for(int j=1;j<=W;j++){
				if(j!=W) cout << A[i][j] << " ";
				else cout << A[i][j] << endl;
			}
		}
	}
}