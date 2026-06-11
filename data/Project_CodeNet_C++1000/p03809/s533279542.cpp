#include <cstdio>
#include <cstring>
#include <string>
#include <cmath>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <deque>
#include <algorithm>

using namespace std;
typedef pair<int, int> P;

int main()
{
	int n;
	scanf("%d", &n);
	long long int A[100000];
	for(int i=0; i<n; i++){
		scanf("%lld", &A[i]);
	}
	vector<int> v[100000];
	map<P, int> e;
	for(int i=0; i<n-1; i++){
		int a, b;
		scanf("%d %d", &a, &b);
		a--;
		b--;
		v[a].push_back(b);
		v[b].push_back(a);
		e[P(a, b)]=i;
		e[P(b, a)]=i;
	}
	int d[100000];
	fill(d, d+n, -1);
	d[0]=0;
	queue<int> que;
	que.push(0);
	while(!que.empty()){
		int x=que.front();
		que.pop();
		for(int i=0; i<v[x].size(); i++){
			if(d[v[x][i]]==-1){
				d[v[x][i]]=d[x]+1;
				que.push(v[x][i]);
			}
		}
	}
	multimap<int, int> dmp;
	for(int i=0; i<n; i++){
		dmp.insert(make_pair(-d[i], i));
	}
	long long int m[100000];
	for(auto itr=dmp.begin(); itr!=dmp.end(); itr++){
		int x=itr->second;
		if(x!=0){
		int vp=-1;
		long long int sum=0;
		if(v[x].size()==1){
			m[e[P(x, v[x][0])]]=A[x];
		}else{
		for(int i=0; i<v[x].size(); i++){
			if(d[v[x][i]]<d[x]){
				vp=v[x][i];
			}else{
				sum+=m[e[P(x, v[x][i])]];
			}
		}
		
		if(vp!=-1) m[e[P(x, vp)]]=2*A[x]-sum;
		}
		}else{
			if(v[0].size()==1){
				if(m[e[P(0, v[0][0])]]!=A[0]){
					printf("%s\n", "NO");
					return 0;
				}
			}else{
				long long int sum=0;
				for(int i=0; i<v[0].size(); i++){
					sum+=m[e[P(0, v[0][i])]];
				}
				if(2*A[0]!=sum){
					printf("%s\n", "NO");
					return 0;
				}
			}
		}
	}
	for(int x=0; x<n; x++){
		if(v[x].size()!=1){
			for(int i=0; i<v[x].size(); i++){
				if(m[e[P(v[x][i], x)]]>A[x] || m[e[P(v[x][i], x)]]<0){
					printf("%s\n", "NO");
					return 0;
				}
			}
		}
	}
	printf("%s\n", "YES");
	return 0;
}
