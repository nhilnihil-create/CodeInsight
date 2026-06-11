#include<iostream>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int MAX=100005;
vector<int> llist[MAX*2];
int n,m,color[MAX*2],appear[MAX],zero,two,one;
long long int ans;
int bfs(int u)
{
	vector<int> used;
	int vertex=0;
	bool flag=false;
	queue<int> q;
	used.push_back(u);
	q.push(u);
	color[u]=1;
	while(!q.empty())
	{
		int v=q.front();
		int r=v;
		q.pop();
		if(v>n){
			r=v-n;
		}
		appear[r]++;
		if(appear[r]==2) flag=true;
		else vertex++;
		for(int i=0;i<llist[v].size();++i){
			int temp=llist[v][i];
			if(color[temp]==0){
				q.push(temp);
				used.push_back(temp);
				color[temp]=1;
			}
		}	
		
	}
	for(int i=0;i<used.size();++i){
		int temp=used[i];
		if(temp>n) temp-=n;
		color[temp]=1;
	}
	if(vertex==1){
		zero++;
		return 0;	
	} 
	if(flag){
		one++;
		return 1;
	}
	two++;
	return 2;
}
int main()
{
	int a,b;
	int sum;
	cin>>n>>m;
	for(int i=1;i<=m;++i){
		cin>>a>>b;
		llist[a+n].push_back(b);
		llist[b+n].push_back(a);
		llist[a].push_back(n+b);
		llist[b].push_back(n+a);
	}
	for(int i=1;i<=n;++i){
		if(color[i]==0){
			int type=bfs(i);
//			cout<<type<<endl;
			if(type==0){
				ans+=(2*(long long int)(n-zero+1)-1);
//				cout<<"shit1"<<endl;
			}
			else if(type==1){
				ans+=2*((long long int)two+(long long int)(one-1))+(long long int)type;
//				cout<<"shit2"<<endl;
			}
			else{
				ans+=2*((long long int)(two-1)*2+(long long int)one)+(long long int)type;
//				cout<<"shit3"<<endl;
			}
//			cout<<i<<" "<<ans<<" "<<two<<" "<<one<<endl;
		}
	}
	cout<<ans<<endl;
	return 0;
}