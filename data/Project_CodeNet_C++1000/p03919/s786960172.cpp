#include<iostream>
using namespace std;

string s;
int main(){
	int h,w; cin >>h>>w;
	int cnth=-1;  int cntw=-1;
	for(int i=0;i<h;i++){
		for(int j=0;j<w;j++){
			cin >> s;
			if(s=="snuke"){
				cnth=i; cntw=j;
			}
		}
	}
	char a='A';
	for(int i=0;i<cntw;i++){
		a++;
	}
	cout << a <<cnth+1 << endl;
}
