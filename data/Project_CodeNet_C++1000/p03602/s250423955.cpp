#include <string>
#include <vector>
#include <sstream>
#include <iostream>
#include <algorithm>
#include <map>
#include <list>
#include <set>
#include <numeric>
#include <queue>
#include <stack>
#include <cstdio>
#include <cmath>
#include <cstdlib>
#include <cctype>
#include <cstring>
#include <climits>
#include <cfloat>
#include <ctime>
#include <complex>
#include <cassert>
#include <array>
#include <bitset> 
#include <unordered_map>
#include <random>

using namespace std;
typedef long long LL;
typedef pair<int,int> P;
typedef array<int,3> B;

int A[300][300];
LL ds[300][300];
vector<B> vs;
int main() {
	int N;
	scanf("%d",&N);
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			scanf("%d",A[i]+j);
			ds[i][j]=1e9+1;
			if(i<j){
				vs.push_back(B{{A[i][j],i,j}});
			}
		}
		ds[i][i]=0;
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			for(int k=0;k<N;k++){
				if(A[i][j]>A[i][k]+A[k][j]){
					puts("-1");
					return 0;
				}
			}
		}
	}
	sort(vs.begin(),vs.end());
	LL ret=0;
	for(auto v:vs){
		int i=v[1];
		int j=v[2];
		int d=v[0];
		if(ds[i][j]>d){
			//cerr << i << ", " << j << ": " << ds[i][j] << ", " << d << endl;
			ret+=d;
			for(int p=0;p<N;p++){
				for(int q=p+1;q<N;q++){
					ds[p][q]=ds[q][p]=min({ds[p][q],ds[p][i]+d+ds[j][q],ds[p][j]+d+ds[i][q]});
				}
			}
		}
	}
	printf("%lld\n",ret);

	return 0;
}

