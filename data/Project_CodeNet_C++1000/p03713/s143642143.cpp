#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string>
#include <stack>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)

using namespace std;
typedef long long int ll;

ll tripleMax(ll a,ll b,ll c){
	return max(a,max(b,c));
}

ll tripleMin(ll a,ll b,ll c){
	return min(a,min(b,c));
}

int main()
{
	ll H,W;
	cin>>H>>W;
	ll minimumDifference = 1000000000000000;
	// cut horizontaly
	for(int h = 1; h < H; h++){
		ll A1,A2,A3;
		A1 = W*h;
		// pattern 1
		int width = W/2;
		A2 = (H-h)*width;
		A3 = (H-h)*(W-width);
		minimumDifference = min( minimumDifference, tripleMax(A1,A2,A3) - tripleMin(A1,A2,A3));

		// pattern 2;
		int height = (H-h)/2;
		A2 = W*height;
		A3 = W*(H-h-height);
		minimumDifference = min( minimumDifference, tripleMax(A1,A2,A3) - tripleMin(A1,A2,A3));
	}

	for(int w = 1; w < W; w++){
		ll A1,A2,A3;
		A1 = H*w;
		//pattern 1
		int height = H / 2;
		A2 = (W-w)*height;
		A3 = (W-w)*(H-height);
		minimumDifference = min( minimumDifference, tripleMax(A1,A2,A3) - tripleMin(A1,A2,A3));

		//pattern 2
		int width = (W-w)/2;
		A2 = H * width;
		A3 = H * (W-w-width);
		minimumDifference = min( minimumDifference, tripleMax(A1,A2,A3) - tripleMin(A1,A2,A3));
	}
	cout<<minimumDifference<<endl;
	return 0;
}
