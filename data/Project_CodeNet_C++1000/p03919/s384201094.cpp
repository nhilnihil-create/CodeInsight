#include<iostream>
#include<math.h>
#include<algorithm>
#include<vector>
#include<queue>
#include<set>

using namespace std;

#define forn(i,n) for(int i=0;i<(int)(n); i++)
#define forsn(i,s,n) for(int i=(s);i<(int)(n); i++)
#define pb push_back

int main(){
	int h, w;
	cin>>h>>w;
	int pos;
	char let;
	string alf="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
	forn(i, h){
		forn(j, w){
			string s;
			cin>>s;
			if(s=="snuke"){
				pos=i+1;
				let=alf[j];
			}
		}
	}
	cout<<let<<pos<<endl;
}
