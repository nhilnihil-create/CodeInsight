#include <iostream>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <map>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <algorithm>
#include <sstream>
#include <istream>

using namespace std;

typedef long long ll;
typedef pair<ll, int> P;


int main(){
	int n,m;
	cin >> n >> m;

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			string s;
			cin >> s;
			if(s=="snuke"){
				printf("%c%d\n",('A'+j),i+1);
			}
		}
	}
	

	return 0;
}