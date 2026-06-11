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
	ll N,K;
	cin>>N>>K;
  	ll ANS=K;
  	for(int i=0;i<N-1;i++){
      ANS=ANS*(K-1);
    }
  	cout << ANS << endl;
}
