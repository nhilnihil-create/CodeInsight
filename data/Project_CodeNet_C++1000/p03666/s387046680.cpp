#include<iostream>
#include<algorithm>
using lint=int64_t;
using namespace std;

int main()
{
	lint N,A,B,C,D;

	cin >> N >> A >> B >> C >> D;

	for(int i=0;i<N;i++)
	{
		if(C*i-D*(N-1-i)<=B-A && B-A<=D*i-C*(N-1-i))
		{
			cout << "YES" << endl;
			return 0;
		}
	}
	
	cout << "NO" << endl;
	return 0;
}

