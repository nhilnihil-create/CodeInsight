#include <algorithm>
#include <iostream>
#include <math.h>
#include <stdio.h>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <map>
#include <cmath>
#include <queue>
#define rep(i, n) for(int i = 0; i < (int)(n); i++)
using namespace std;
typedef unsigned long long ll;


int main()
{
	int n;
	cin>>n;
	vector<int> a(n);
	vector<bool> visited(n,false);
	visited[0] = true;
	for(int i = 0; i < n; i++){
		int num;
		cin>>num;
		num--;
		a[i] = num;
	}
	bool ans = true;
	int next = a[0];
	int count = 1;
	while( next != 1){
		visited[next] = true;
		next = a[next];
		count++;
		if( next == 1){
			ans = true;
			break;
		}else if( visited[next] == false){
			// do nothing
		}else{
			ans = false;
			break;
		}
	}
	if( ans == true){
		cout<<count<<endl;
	}else{
		cout<<-1<<endl;
	}
	return 0;
}

