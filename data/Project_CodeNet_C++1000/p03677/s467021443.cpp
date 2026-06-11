#include <iostream>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <cstdio>
#include <vector>
#include <set>
#include <cassert>
#include <cstdlib>
#include <complex>
#include <cctype>
#include <cmath>
#include <ctime>
#include <deque>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <sstream>
#include <functional>
#include <iomanip>
//#include <windows.h>  //Should be deleted when using AtCoder&POJ
using namespace std;

#define ll long long
#define pii pair<int,int>
#define qi ios::sync_with_stdio(0)
/**==Info==
*Program:6
*Problem:guruguru
*Date:2019-5-11
*Algorithm:MK's sweep line
*Stats:Unknown*/

bool debug=false;

struct line{
	int st;
	int ed;
	int len;
};

line line[100005];

int n,k;
int a[100005];
int main(int argc,char* argv[]){
	qi;
	cin>>n>>k;
	for(int i=0;i<n;i++){
		cin>>a[i];
		a[i]--;
	}
	
	ll nw=0,pre=0;
	for(int i=0;i<n-1;i++){
		int grass=a[i],hopper=a[i+1];
		if(hopper<grass){
			hopper+=k;
		}
		
		nw+=hopper-grass;
		if(hopper-grass<=1){
			continue;
		}
		
		grass+=2;
		
		if(grass>=k && hopper>=k){
			grass-=k;
			hopper-=k;
		}else{
			if(grass<k && hopper>=k){
				hopper-=k;
				line[0].st++;
				line[grass].st++;
				line[hopper].len+=hopper+k-grass+1;
				line[hopper].ed++;
				pre+=k-grass;
				continue;
			}
		}
		
		
		line[grass].st++;
		line[hopper].ed++;
		line[hopper].len+=hopper-grass+1;
	}
	
	ll ans=nw;
	ll inr=0;
	ll sex=nw;
	sex-=pre;
	for(int i=0;i<=k;i++){
		inr+=line[i].st;
		sex-=inr;
		ans=min(ans,sex);
		inr-=line[i].ed;
		sex+=line[i].len;
	}
	
	cout<<ans;
	return 0;
}

