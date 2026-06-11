#include <bits/stdc++.h>
using namespace std;
#define rep(i,N) for(int i=0;i<int(N);++i)
using ll = long long;
const int INF = 2147483647;

//a,b,cを受け取って1,2,3を返す
int func(char a){
	if(a=='a')
		return 1;
	if(a=='b')
		return 2;
	if(a=='c')
		return 3;
}

int main(){
	string sa,sb,sc;
	cin >> sa >> sb >> sc;
	int a=0;
	int b=0;
	int c=0;
	int now=1; //最初はaさんから
	int win = -1;
	while(1){
		if(now==1){
			now=func(sa[a]);
			a++;
		}
		if(now==2){
			now=func(sb[b]);
			b++;
		}
		if(now==3){
			now=func(sc[c]);
			c++;
		}
		if(a>sa.size()){
			win = 1;
			break;
		}
		if(b>sb.size()){
			win = 2;
			break;
		}
		if(c>sc.size()){
			win = 3;
			break;
		}
	}
	if(win==1) cout << 'A' << endl;
	if(win==2) cout << 'B' << endl;
	if(win==3) cout << 'C' << endl;
	return 0;
}
