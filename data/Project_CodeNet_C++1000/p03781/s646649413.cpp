#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <queue>
#include <set>
#include <cmath>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)

using namespace std;
typedef long long int lli;
const int MAX=1e9;

int main(){
	int x;
	cin>>x;
	int ans;
	rep1(i,100000)if(x<=i*(i+1)/2){ans=i;break;}
	cout<<ans<<endl;
}