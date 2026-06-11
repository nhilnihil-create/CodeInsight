#include<iostream>
#include<cstring>
using namespace std;

const int maxn=1e5+2;

struct ball{
	int s;
	int red;
}ball[maxn];

void move(int x,int y){
	if(ball[x].s<1)return;
	if(ball[x].s==1){
		ball[x].s--;
		ball[y].s++;
		if(ball[x].red){
			ball[y].red=true;
			ball[x].red=0;
		}
//		cout<<x<<":"<<ball[x].red<<endl;
//		cout<<y<<":"<<ball[y].red<<endl;
	}
	else{
		ball[x].s--;
		ball[y].s++;
		if(ball[x].red)
			ball[y].red=1;
//		cout<<x<<":"<<ball[x].red<<endl;
//		cout<<y<<":"<<ball[y].red<<endl;
	}
}

int main(){
	int n,m,x,y;
	cin>>n>>m;
	
	ball[1].red=1;
	ball[1].s=1;
	for(int i=2;i<=n;i++){
		ball[i].s=1;
		ball[i].red=0;
	}
	
	for(int i=0;i<m;i++){
		
		cin>>x>>y;
		move(x,y);
		
	}
	int cnt=0;
	for(int i=1;i<=n;i++)
		if(ball[i].red==1)cnt++;
	cout<<cnt<<endl;
	
	return 0;
}