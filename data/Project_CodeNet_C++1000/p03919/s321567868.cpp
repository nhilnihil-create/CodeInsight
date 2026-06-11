#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
#include <queue>
#include <set>
#include <cmath>
#include <map>
using namespace std;

int H, W;
string s;
string mozi="snuke";
string alpha="ABCDEFGHIJKLMNOPQRSTUVWXYZ";

int main()
{
	cin >> H >> W;
	for(int i=1; i<H+1; i++){
		for(int j=0; j<W; j++){
			string inp;
			cin >> inp;
			if(inp==mozi){
				cout << alpha[j] << i << endl;
				return 0;
			}
		}
	}
}
