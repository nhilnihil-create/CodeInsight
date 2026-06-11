#include <iostream>
#include <iomanip>
#include <ios> 
#include <vector>
#include <string>
#include <algorithm>
#include <functional>
#include <queue>
#include <stack>
#include <set>
#include <cmath>
#include <bitset>
#include <map>
#define rep(i,n) for(int (i)=0;(i)<(n);(i)++)
#define rep1(i,n) for(int i=1;i<=(int)(n);i++)

using namespace std;
typedef long long int lli;
//const int MAX=;

int main(){
	int N;
	cin>>N;
	
	int mx;
	rep1(i,1e4){
		if(i*(i+1)/2>=N){
			mx=i;
			break;
		}
	}
	int sum=N;
	int prob=mx;
	while(sum>0){
		if(sum>=prob){
			cout<<prob<<endl;
			sum-=prob;
		}
		prob--;
	}
}