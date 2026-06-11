#include <cstdio>
#include <algorithm>
#include <cassert>
#include <cstdlib>
using namespace std;

int N,M,D;
char a[999][999];
char t[2][2]={{'R','Y'},{'G','B'}};

void solve(){

	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			int x = (-i+j+N)/D, y = (i+j+N)/D;
			x%=2, y%=2;
			a[i][j]=t[x][y];
		}
	}

	for(int i=0;i<N;i++){
		puts(a[i]);
	}


}

int main(){

	scanf("%d%d%d",&N,&M,&D);
	solve();

	return 0;
}