#include<cstdio>
#include<algorithm>
#include<vector>
#include<set>
#include<queue>
#include<string>
#include<iostream>
#define R(i, n) for(int i = 0; i < n; i++)
#define S(a) scanf("%d", &a)
#define S2(a, b) scanf("%d%d", &a, &b)
#define S3(a, b, c) scanf("%d%d%d",  &a, &b, &c)
#define SL(a) scanf("%lld", &a)
#define P(a) printf("%d\n", a)
#define PY printf("%s", "Yes");
#define PN printf("%s", "No");
#define INF 1000000000
using namespace std;
typedef long long ll;
typedef pair<int, int> IR;

int main(){
	int n, a, b;
	string s;
	S3(n, a, b);
	cin >> s;
	int count = 0;
	int bnum = 0;
	R(i, n){
		if(s[i] == 'a'){
			if(count < a + b){
				PY;
				printf("\n");
				count++;
			}
			else{
				PN;
				printf("\n");
			}
		}
		else if(s[i] == 'b'){
			if(count < a + b && bnum < b){
				PY;
				printf("\n");
				count++;
				bnum++;
			}
			else{
				PN;
				printf("\n");
			}
		}
		else{
				PN;
				printf("\n");
		}
	}
}