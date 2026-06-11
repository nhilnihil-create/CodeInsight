#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <algorithm>
#include <fstream>
#include <string>
#include <math.h>
#include <cstdlib>
#include <istream>
#include <sstream>
#include <cctype>
#define fore(i,x,y) for(long long i=x;i<y;i++)
typedef long long ll;
using namespace std;
int main()
{
	int N,ANS=0;
	cin >> N;
	for(int i=0;i<N;i++){
		int a,b;
		cin >> a >> b;
		ANS=ANS+b-a+1;
	}
	cout << ANS << endl;
}