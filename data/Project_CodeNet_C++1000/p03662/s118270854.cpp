#include<bits/stdc++.h>
using namespace std;
int n,a,b;
vector<int>v[100003];
int color[100003];
int main(){
	queue<int>q;
	cin>>n;
	for(int i=1;i<n;i++)
	{
		cin>>a>>b;
		a--;b--;
		v[a].push_back(b);
		v[b].push_back(a);
	}
	q.push(0);q.push(n-1);
	color[0]=1;color[n-1]=2;
	while(q.size()){
		for(int i=0;i<v[q.front()].size();i++)
			if(!color[v[q.front()][i]])
				color[v[q.front()][i]]=color[q.front()],
				q.push(v[q.front()][i]);
		q.pop();
	}
	a=0;b=0;
	for(int i=0;i<n;i++)
		if(color[i]==1)
			a++;
		else
			b++;
	if(a>b)
		cout<<"Fennec";
	else
		cout<<"Snuke";
}