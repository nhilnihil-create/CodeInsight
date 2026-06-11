#include <cstdio>
#include <vector>
#include <algorithm>

#define PB push_back

using namespace std;

const int N = 1e5 + 500;

int n, m, A[N];
vector < int > a, b, nep;


int main(){
	scanf("%d%d", &n, &m);
	if(m == 1){
		int x; scanf("%d", &x);
		if(x == 1){
			printf("1\n1\n1\n");
			return 0;
		}
		printf("%d\n2\n%d %d\n", x, 1, x - 1);
		return 0;
	}
	for(int i = 0;i < m;i++){
		scanf("%d", A + i);
		if(A[i] % 2){
			nep.PB(A[i]);
		}
		else{
			a.PB(A[i]);
		}
	} 
	if((int)nep.size() > 0)
		a.insert(a.begin(), nep[0]);
	if((int)nep.size() > 1)
		a.PB(nep[1]);
	if((int)nep.size() > 2){
		printf("Impossible\n");
		return 0;
	}
	for(int i = 0;i < (int)a.size();i++){
		if(!i){
			if(a[i] - 1)
				b.PB(a[i] - 1);
			b.PB(2);
		}
		else if(i + 1 < (int)a.size()){
			b.PB(a[i]);
		}
		else{
			if(a[i] - 1)
				b.PB(a[i] - 1);
		}
	}
	for(int x : a)
		printf("%d ", x);
	printf("\n");
	printf("%d\n", (int)b.size());
	for(int x : b)
		printf("%d ", x);
	printf("\n");
	return 0;
	
}