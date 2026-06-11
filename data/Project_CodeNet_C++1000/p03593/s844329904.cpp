#include <cstdio>
#include <iostream>
using namespace std;

const int MAXN = 205;
int q;
int n, m;	
int t[27];
char ch[MAXN];

void init() {
	for(int i = 0; i <= 26; ++ i)
		t[i] = 0;
}

void work1() {
	bool flag = false;
	for(int i = 0; i <= 26; ++ i) 
		if((t[i] & 1) || ((t[i] >> 1) & 1)) {
			flag = true;
			break;
		}
	printf("%s\n", flag ? "No" : "Yes");
}

void work2() {
	int cnt = 0, tot = 0;
	for(int i = 0; i <=26; ++ i) {
		if(t[i] & 1) 
			cnt ++ ;
		if((t[i] >> 1) & 1)
			tot ++ ;
	}
	int Max = (n & 1) ? (m >> 1) : (n >> 1);
	printf("%s\n", (cnt || tot > Max) ? "No" : "Yes"); 
}

void work3() {
	int cnt = 0, tot = 0;
	for(int i = 0; i <=26; ++ i) {
		if(t[i] & 1) 
			cnt ++ ;
		if((t[i] >> 1) & 1)
			tot ++ ;
	}
	int Max = ((n - 1) >> 1) + ((m - 1) >> 1);
	printf("%s\n", (cnt > 1 || tot > Max) ? "No" : "Yes");
}

int main() {
//	freopen("quilt.in", "r", stdin);
//	freopen("quilt.out", "w", stdout);
	init();
	scanf("%d%d", &n, &m);
	for(int i = 1; i <= n; ++ i) {
		scanf("%s", ch + 1);
		for(int j = 1; j <= m; ++ j)
			t[ch[j] - 'a'] ++ ;
	}
	if( ! (n & 1) && ! (m & 1)) { // both ou
		work1();
	} else if((n & 1) && ! (m & 1) || ! (n & 1) && (m & 1)) { // one ou one ji 
		work2();
	} else { // both ji
		work3();
    }
	return 0;
}