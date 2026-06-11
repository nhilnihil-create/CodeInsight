#include <algorithm>
#include <iostream>
#include <vector>
#include <queue>
#include <set>
#include <map>
#include <list>
#include <cmath>
#include <stack>
#include <string>
#include <cstring>
#include <numeric>
#include <iomanip>
using namespace std;
//
const int inf=1e9+7;//0x3f
//
int main(){
	int N;
	cin>>N;
	vector<int> V(N);
	for(int i=0;i<N;i++){
		cin>>V[i];
	}
	int ans=0;
	for(int i=0;i+1<N;i++){
		if(i+1==V[i]&&i+2==V[i+1]){
			swap(V[i],V[i+1]);
			ans++;
		}
	}
	for(int i=0;i<N;i++){
		if(i+1==V[i]){
			ans++;
		}
	}
	cout<<ans<<endl;
	return 0;
}