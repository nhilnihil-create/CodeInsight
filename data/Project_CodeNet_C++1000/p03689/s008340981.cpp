#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

#define POSITIVE ((int)(1000))
#define NEGATIVE ((int)((-POSITIVE) * (h * w - 1) - 1))

using namespace std;

typedef long long i64;

int H, W, h, w;


int main()
{

	cin >> H >> W >> h >> w ;

	if(H % h == 0 && W % w == 0)
	{
		cout << "No" << endl ;
		return 0;
	}
	cout << "Yes" << endl ;
	for(int i = 1; i <= H; i++)
	{
		for(int j = 1; j <= W; j++)
		{
			if(i % h > 0 || j % w > 0)
				cout << POSITIVE ;
			else
				cout << NEGATIVE ;
			cout << " " ;
		}
		cout << endl ;
	}


	return 0;
}

