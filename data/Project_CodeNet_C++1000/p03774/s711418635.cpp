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
typedef long long ll;

int manLength(int x1,int y1,int x2,int y2){
	return abs(x1-x2) + abs(y1-y2);
}
int main()
{
	int n,m;
	cin>>n>>m;
	vector<pair<int,int>> students(n);
	vector<pair<int,int>> points(m);
	for(int i = 0; i < n; i++){
		cin>>students[i].first>>students[i].second;
	}
	for(int i = 0; i < m; i++){
		cin>>points[i].first>>points[i].second;
	}
	for(int i = 0; i < n; i++){
		int length = manLength(students[i].first,students[i].second,points[0].first,points[0].second);
		int currentPoint = 0;
		for(int j = 1; j < m; j++){
			if(length > manLength(students[i].first,students[i].second,points[j].first,points[j].second)){
				currentPoint = j;
				length = manLength(students[i].first,students[i].second,points[j].first,points[j].second);
			}
		}
		cout<<currentPoint+1<<endl;
	}
	return 0;
}

