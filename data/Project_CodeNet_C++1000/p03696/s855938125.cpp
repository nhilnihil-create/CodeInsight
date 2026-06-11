#include<bits/stdc++.h>
typedef long long int ll;
typedef unsigned long long int ull;
#define BIG_NUM 2000000000
#define HUGE_NUM 1000000000000000000
#define MOD 1000000007
#define EPS 0.000000001
using namespace std;


int N;
string T,work;

int main(){

	scanf("%d",&N);
	cin >> T;
	work = T;

	stack<int> S;

	for(int i = 0; i < N; i++){
		if(work[i] == '('){

			S.push(i);

		}else{ //work[i] == ')'

			if(S.empty()){

				T = '(' + T;
			}else{

				S.pop();
			}
		}
	}

	while(!S.empty()){

		T = T+')';
		S.pop();
	}

	printf("%s\n",T.c_str());

	return 0;
}
