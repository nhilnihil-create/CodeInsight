#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <vector>
#include <deque>
#include <queue>
#include <stack>
#include <set>
#include <map>
#include <algorithm>
#include <functional>
#include <utility>
#include <bitset>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <cstdio>
#include <memory.h>
#include <iomanip>
#include <unordered_set>
#include <unordered_map>
using namespace std;

const int Maxn=1005;

int h,w,d;

int main(){
	scanf("%d%d%d",&h,&w,&d);
	for(int i=1;i<=h;i++){
		for(int j=1;j<=w;j++){
			int x=i+j+1000*d,y=i-j+1000*d;
			x%=2*d;
			y%=2*d;
			if(!x) x=2*d;
			if(!y) y=2*d;
			if(x<=d){
				if(y<=d) printf("R");
				else printf("Y");
			}
			else{
				if(y<=d) printf("G");
				else printf("B");
			}
		}
		printf("\n"); 
	}
return 0;
}