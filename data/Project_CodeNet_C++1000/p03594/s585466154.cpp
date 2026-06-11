#include <cstdio>
#include <cstring>
#include <iostream>
#include <string>
#include <cmath>
#include <bitset>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>

using namespace std;
typedef long long int ll;
typedef pair<int, int> P;

int main()
{
	int h, w, d;
	scanf("%d %d %d", &h, &w, &d);
	int e=0;
	while(d%2==0){
		d/=2;
		e++;
	}
	char c[500][500];
	if(e==0){
		for(int i=0; i<h; i++){
			for(int j=0; j<w; j++){
				if((i+j)%2==0) c[i][j]='R';
				else c[i][j]='Y';
			}
		}
	}else{
		for(int i=0; i<h; i++){
			for(int j=0; j<w; j++){
				int i0=i, j0=j;
				if((i0+j0)%2==1) i0--;
				if(((i0+j0)%(1<<(e+1)))<(1<<e) && ((i0-j0%(1<<(e+1))+(1<<(e+1)))%(1<<(e+1)))<(1<<e)){
					c[i][j]='R';
				}else if(((i0+j0)%(1<<(e+1)))<(1<<e) && ((i0-j0%(1<<(e+1))+(1<<(e+1)))%(1<<(e+1)))>=(1<<e)){
					c[i][j]='Y';
				}else if(((i0+j0)%(1<<(e+1)))>=(1<<e) && ((i0-j0%(1<<(e+1))+(1<<(e+1)))%(1<<(e+1)))<(1<<e)){
					c[i][j]='G';
				}else{
					c[i][j]='B';
				}
			}
		}
	}
	for(int i=0; i<h; i++){
		for(int j=0; j<w; j++){
			cout<<c[i][j];
		}
		cout<<endl;
	}
    return 0;
}