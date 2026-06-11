#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int rect[200][200];

int main(void){
	int w,h,n;
	cin>>w>>h>>n;
	int r = w*h;
	while(n--){
		int x,y,a;
		cin>>x>>y>>a;
		if(a == 1){
			for(int i = x-1; i >= 0; i--)
			  for(int j = 0; j < h; j++){
				if(!rect[i][j]) r--;
				rect[i][j] = 1;
			  }
		}else if(a == 2){
			for(int i = x; i < w; i++)
			  for(int j = 0; j < h; j++){
				if(!rect[i][j]) r--;
				rect[i][j] = 1;
			  }
		}else if(a == 3){
			for(int i = 0; i < w; i++)
			  for(int j = y-1; j >=0; j--){
				if(!rect[i][j]) r--;
				rect[i][j] = 1;
			  }
		}else{
			for(int i = 0; i < w; i++)
			  for(int j = y; j < h; j++){
				if(!rect[i][j]) r--;
				rect[i][j] = 1;
			  }
		}
	}
	cout<<r<<'\n';
	return 0;
}
