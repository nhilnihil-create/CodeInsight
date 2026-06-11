#include<iostream>
#include<sstream>
#include<fstream>
#include<string>
#include<vector>
#include<deque>
#include<queue>
#include<stack>
#include<set>
#include<map>
#include<algorithm>
#include<functional>
#include<utility>
#include<bitset>
#include<cmath>
#include<cstdlib>
#include<ctime>
#include<cstdio>

using namespace std;

#define REP(i,n) for(int i=0;i<int(n);i++)
#define foreach(c,itr) for(__typeof((c).begin()) itr=(c).begin();itr!=(c).end();itr++)
typedef long long ll;
typedef pair<int,int> P;


int main(void){
	ll i;

	ll N;
	cin >> N;
	ll p=-1,x=-1;
	for(i=1;i<=N;i++){
		x=i*(i+1)/2;
		if(x>=N){
			p=i; break;
		}
	}

	for(i=1;i<=p;i++){
		if(i==x-N) continue;
		cout << i << endl;
	}


	return 0;
}
