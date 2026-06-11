#include<iostream>
#include<algorithm>
#include<string>
#include<vector>
#include<set>
using namespace std;

typedef long long ll;
typedef pair<int,int> P;

#define pb push_back
#define fr first
#define sc second

char col[4] = { 'R', 'G', 'B', 'Y', };

char sol(int x,int y,int d){
	if(d&1){
		return col[(x^y)&1];
	}
	if((x^y)&1)return sol(x+1,y,d);
	int s = x+y;
	int t = x-y;
	while(t < 0)t += 2*d;
	s %= 2*d;
	t %= 2*d;
	return col[((s<d)?0:2)+((t<d)?0:1)];
}

int main(){
	int H,W,d;
	scanf("%d%d%d",&H,&W,&d);
	
	for(int i = 0 ; i < H ; i ++){
		for(int j = 0 ; j < W ; j ++){
			printf("%c",sol(i,j,d));
		}
		printf("\n");
	}
}

