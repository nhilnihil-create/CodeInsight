#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<string.h>
#include<math.h>
#include<map>
#include<iomanip>

#define MOD 1e9+7;
#define INF 1e17+9;
#define PI acos(-1);

using namespace std;

int main(){
	string S;
	cin >> S;
	int N=S.size();
	int n,s,e,w;
	n=s=e=w=0;
	for(int i=0;i<N;i++){
		if(S[i]=='N')n++;
		if(S[i]=='S')s++;
		if(S[i]=='E')e++;
		if(S[i]=='W')w++;
	}
	
	//cout << n << s << e << w << endl;
	
	if(n==0&&s==0&&e>0&&w>0){
		cout << "Yes" << endl;
	}else if(n>0&&s>0&&e==0&&w==0){
		cout << "Yes" << endl;
	}else if(n>0&&s>0&&e>0&&w>0){
		cout << "Yes" << endl;
	}else{
		cout << "No" << endl;
	}
	
	return 0;
}
