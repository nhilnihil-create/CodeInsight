#include<iostream>
#include<vector>
#include<algorithm>
#include<string>

using namespace std;

int main()
{
	int w,h,n,i,j;
	cin >> w >> h >> n;
	int x,y,a,x_1,y_1,x_2,y_2;
	x_1 = y_1 = 0;
	x_2 = w;	y_2 = h;

	for(i=0; i<n; i++){
		cin >> x >> y >> a;
		if(a == 1)
			x_1 = max(x,x_1);
		else if(a == 2)
			x_2 = min(x,x_2);
		else if(a == 3)
			y_1 = max(y,y_1);
		else if(a == 4)
			y_2 = min(y,y_2);	
	}
	if(x_2 <= x_1 || y_2 <= y_1){
		cout << 0 << endl;
		return 0;
	}
	cout << (x_2 - x_1) * (y_2 - y_1) << endl;


}
