#include <cstdio>
#include <algorithm>
#include <cstring>
#define N 2105
#define M 1005
#include <cstdlib>
#define fi(a, b, c) for(int a = (b); a < (c); a++)
#define FI(a, b, c) for(int a = (b); a <= (c); a++)
using namespace std;

int n, m, d, s[N][N], cnt;
char *c = "BGYR";
bool vis[N][N];

void fill(int y, int x, int col){
	int l = d / 2 - 1;
	
	if(y + l < 0 || y - l >= n || x >= m || x + d - 1 < 0) return;
	
	FI(i, -l, l){
		int ny = y + i;
		FI(j, abs(i), d - 1 - abs(i)){
			int nx = x + j;
			if(ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
			s[ny][nx] = col;
		}
	}
}

void dfs(int y, int x){
	if(y < -d - d || x < -d - d || y > n + d || x > m + d) return;
	if(vis[y + M][x + M]) return;
	vis[y + M][x + M] = 1;
	
	fill(y, x + d, 1);
	fill(y + d / 2, x + d / 2, 2);
	fill(y + d / 2, x - d / 2, 3);
	
	dfs(y - 1, x - d - d + 1);
	dfs(y + 1, x + d + d - 1);
	dfs(y + d + 1, x + d - 1);
	dfs(y - d - 1, x - d + 1);
}


int main(){
	scanf("%d %d %d", &n, &m, &d);
	
	if(d % 2){
		fi(i, 0, n) fi(j, 0, m){
			s[i][j] = (i + j) % 2;
		}
	}else{
		dfs(0, 0);
	}
	
	fi(i, 0, n) fi(j, 0, m){
		FI(k, 0, d){
			int sgn[2] = {-1, 1};
			
			fi(l, 0, 2){
				int ny = i + sgn[l] * (d - k);
				int nx = j + k;
				if(ny < 0 || ny >= n || nx >= m) continue;
				
				if(s[ny][nx] == s[i][j]){
					printf("fail %d %d %d %d\n", i, j, ny, nx);
				}
			}
		}
	}
	
	fi(i, 0, n){
		fi(j, 0, m) printf("%c", c[s[i][j]]);
		puts("");
	}
	
}

/*
??2??
?222
222221
3222111
33211111
3330111
330001
300000
--000
---0

1003311
0000111
3002211
3322223
3112233

33322
33222233
011223333
1111003311
 110000111100
  330022110000
 3333222233
  3311223333
   111100
    110000
	  00
	 0000  
  33000000
 33330000
33333300
    
int l = d / 2 - 1;

FI(i, -l, l){
	int ny = y + i;
	FI(j, abs(i), d - 1 - abs(i))
		int nx = x + j;
		s[ny][nx] = col;
	}
}
    
  133333
 111333
111113
 111
  1
022201333
002311130
0133312000
111302220
 1200023
 22201333
  2 1113
*/