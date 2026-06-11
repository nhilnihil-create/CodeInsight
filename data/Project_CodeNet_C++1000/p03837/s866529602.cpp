#include <bits/stdc++.h>
#define max 1010

using namespace std;

struct edge{
	int cost;
	int to;
	int from;
};
edge miti[max];
struct p_que{
	int heap[max];
	int index[max];
	int now;
};

int cost[max];

struct p_que* make();
void push(p_que *p, int num,int id);
int smal(p_que *p,int p_id);
int pop(p_que *p);

void dainyu(int a[],int b[], int c[], int m);

int d_stra(int a,int b,int c,int node_num, int edge_num);
int main(void)
{
	int n,m; cin>>n>>m;
	int a[m],b[m],c[m]; for(int i = 0; i < m; i++) cin>>a[i]>>b[i]>>c[i];
	dainyu(a,b,c,m);
	
	int ans = 0;
	for(int i = 0; i < m; i++){
		int start_node = a[i];
		int goal_node = b[i];
		if(d_stra(a[i]-1,b[i]-1,c[i],n,m) == 1) ans++;
	}
	
	cout<<ans<<endl;
	/*
	for(int i = 0; i < m; i++){
		cout<<"miti[i].to = "<<miti[i].to<<", miti[i].from = "<<miti[i].from<<", miti[i].cost = "<<miti[i].cost<<endl;
	}
	*/
	return 0;
}

void dainyu(int a[],int b[], int c[], int m){
	for(int i = 0; i < m; i++){
		miti[i].to = a[i]-1;
		miti[i].from = b[i]-1;
		miti[i].cost = c[i];
	}
}

int d_stra(int a,int b,int c,int node_num,int edge_num){
	//cout<<"a = "<<a<<", b = "<<b<<", c = "<<c<<endl;
	p_que *pq;
	pq = make();
	for(int i = 0; i < node_num; i++) cost[i] = c;
	cost[a] = 0;
	while(cost[a] < c && a != b){
		for(int i = 0; i < edge_num; i++){
			if(a == miti[i].to && miti[i].cost +cost[a] <= c && miti[i].cost+cost[a] < cost[miti[i].from]){
				if(miti[i].from == b && miti[i].cost+cost[a] < c) return 1;
				push(pq,cost[a]+miti[i].cost,miti[i].from);
				cost[miti[i].from] = cost[a]+miti[i].cost;
			}
			if(a == miti[i].from && miti[i].cost + cost[a] <= c && miti[i].cost+cost[a] < cost[miti[i].to]){
				if(miti[i].to == b && miti[i].cost+cost[a] < c) return 1;
				push(pq,cost[a]+miti[i].cost,miti[i].to);
				cost[miti[i].to] = cost[a]+miti[i].cost;
			}
		}
		if(pq->now == 0) return 2;
		a = pop(pq);
	}
	/*
	for(int i = 0; i < node_num; i++){
		cout<<"i = "<<i<<", cost[i] = "<<cost[i]<<endl;
	}
	cout<<endl;
	*/
	return 2;
}



struct p_que* make(){
	struct p_que *re;
	re = (struct p_que*)malloc(sizeof(struct p_que));
	if(re == NULL){
		cout<<"Eroor"<<endl;
		return 0;
	}
	else {
		re->now = 0;
		for(int i=0; i < max; i++){
			re->heap[i] = max;
			re->index[i] = 0;
		}
		return re;
	}
}

void push(p_que *p,int num,int id){
	int tmp = 0;
	int c_id = p->now;
	p->heap[c_id] = num;
	p->index[c_id] = id;
	while(p->heap[(c_id-1)/2] > p->heap[c_id]){
		tmp = p->heap[(c_id-1)/2]; p->heap[(c_id-1)/2] = num; p->heap[c_id] = tmp;
		tmp = p->index[(c_id-1)/2]; p->index[(c_id-1)/2] = id; p->index[c_id] = tmp;
		c_id = (c_id-1)/2;
		if(c_id == 0) break;
	}
	p->now++;
}

int smal(p_que *p,int p_id){
	if(p->heap[p_id*2+2] < p->heap[p_id*2+1]) return p_id*2+2;
	else return p_id*2+1;
}

int pop(p_que *p){
	if(p->now == 0) return -1;
	int tmp,min,p_id = 0, re = p->index[0];
	p->now--;
	p->heap[0] = p->heap[p->now];
	p->index[0] = p->index[p->now];
	while(p->now > p_id*2+1){
		if(p->now > p_id*2+2) min = smal(p,p_id);
		else min = p_id*2+1;
		if(p->heap[min] < p->heap[p_id]){
			tmp = p->heap[min]; p->heap[min] = p->heap[p_id]; p->heap[p_id] = tmp;
			tmp = p->index[min]; p->index[min] = p->index[p_id]; p->index[p_id] = tmp;
			p_id = min;
		}
		else break;
	}
	return re;
}