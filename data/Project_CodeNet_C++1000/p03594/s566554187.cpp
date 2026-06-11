#include <bits/stdc++.h>

using namespace std;

typedef long long LL;
typedef pair<int , int> P2;
typedef pair<pair<int , int> , int> P3;
typedef pair<pair<int , int> , pair<int , int> > P4;
#define PB(a) push_back(a)
#define MP(a , b) make_pair((a) , (b))
#define M3P(a , b , c) make_pair(make_pair((a) , (b)) , (c))
#define M4P(a , b , c , d) make_pair(make_pair((a) , (b)) , make_pair((c) , (d)))
#define repp(i,a,b) for(int i = (int)(a) ; i < (int)(b) ; ++i)
#define repm(i,a,b) for(int i = (int)(a) ; i > (int)(b) ; --i)

const int MC = 500;
int H,W,d;
char c[7] = "RYGB";

int main(){
	cin >> H >> W >> d;
	int z = 0;
	repp(i,0,H){
		repp(j,0,W){
			int x = i+j+MC , y = i-j+MC;
			cout << c[(x/d%2)*2+(y/d%2)];
		}
		cout << endl;
	}
	return 0;
}
