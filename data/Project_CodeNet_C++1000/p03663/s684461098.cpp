#include <cstdio>
#include <iostream>
#include <cmath>
#include <cstring>
#include <sstream>
#include <algorithm>
#include <cstdlib>
#include <map>
#include <queue>
#include <utility>
#include <vector>
#include <set>
#include <memory.h>
#include <iomanip>
#include <bitset>
#include <list>
#include <stack>
#include <deque>
#include <numeric>

using namespace std;

#define mod 1000000007

int main()
{
	// 桁数を求める
	int keta = -1;
	for(int i = 1; i <= 10; i++){
		cout << "? " << 1 << string(i - 1, '0') << endl;
		char ans;
		cin >> ans;
		if(ans == 'N'){
			keta = i - 1;
			break;
		}
	}
	if(keta == -1){
		// 1, 10, 100, ... のとき、ここにくる
		for(int i = 1; i <= 10; i++){
			cout << "? " << 2 << string(i - 1, '0') << endl;
			char ans;
			cin >> ans;
			if(ans == 'Y'){
				cout << "! " << 1 << string(i - 1, '0') << endl;
				return 0;
			}
		}
	}

	int l = (int)pow(10, keta - 1);
	int r = (int)pow(10, keta) - 1;
	while(r - l > 1){
		int m = (l + r) / 2;
		cout << "? " << m << "0" << endl;
		char ans;
		cin >> ans;
		if(ans == 'Y') r = m;
		else l = m;
	}
	cout << "! " << r << endl;

}