#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
#define lol(i,n) for(int i=0;i<n;i++)
#define mod 100000007
typedef long long ll;
using namespace std;

int main(){
	int h,w;
	cin>>h>>w;
	string s;
	int x,y;
	lol(i,h)lol(j,w){
		cin>>s;
		if(s=="snuke"){
			x=j,y=i;
		}
	}
	char z=x+'A';
	cout<<z<<y+1<<endl;
	return 0;
}
