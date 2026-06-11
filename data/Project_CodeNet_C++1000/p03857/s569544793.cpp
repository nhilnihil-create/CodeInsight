#include<iostream>
#include<vector>
#include<set>
#include<stack>
#include<map>

struct vert{
	int key;
	int prev;
};

void gpaphColoring(std::vector<int> &coloredNode, std::vector<std::vector<int>> graph){
	int color= 0;	
	for(int i=0; i<coloredNode.size(); i++){
		if(coloredNode[i]>= 0)
			continue;

		std::stack<int> path;
		std::stack<vert> dfs;
		dfs.push({i, -1});

		while(!dfs.empty()){
			int cur= dfs.top().key;
			dfs.pop();	

			coloredNode[cur]= color;
			path.push(cur);

			bool isLeaf= true;
			for(int i=0; i<graph[cur].size(); i++){
				int dst= graph[cur][i];
				if(coloredNode[dst]<0){
					dfs.push({dst, cur});
					isLeaf= false;
				}
			}

			if(isLeaf){
				while(!dfs.empty()){
					if(dfs.top().prev==path.top())
						break;
					else
						path.pop();
				}
			}
		}
		color++;	
	}

}

int main(){
	int n, k, l;
	std::vector<std::vector<int>> graph1;
	std::vector<std::vector<int>> graph2;
	std::vector<int> coloredNode1;
	std::vector<int> coloredNode2;
	std::cin>>n>>k>>l;

	coloredNode1.resize(n, -1);
	coloredNode2.resize(n, -1);

	graph1.resize(n);
	graph2.resize(n);

	for(int i=0; i<k; i++){
		int src, dst;
		std::cin>>src>>dst;
		graph1[src-1].push_back(dst-1);
		graph1[dst-1].push_back(src-1);
	}

	for(int i=0; i<l; i++){
		int src, dst;
		std::cin>>src>>dst;
		graph2[src-1].push_back(dst-1);
		graph2[dst-1].push_back(src-1);
	}

	gpaphColoring(coloredNode1, graph1);
	gpaphColoring(coloredNode2, graph2);

	std::map<long long, int> vertGroup;

	for(int i=0; i<n; i++){
		long long idx= (long long)n * (long long)coloredNode1[i] + (long long)coloredNode2[i];
		vertGroup[idx]=0;
	}

	for(int i=0; i<n; i++){
		long long idx= (long long)n * (long long)coloredNode1[i] + (long long)coloredNode2[i];
		vertGroup[idx]= vertGroup[idx]+1;
	}

	for(int i=0; i<n; i++){
		long long idx= (long long)n * (long long)coloredNode1[i] + (long long)coloredNode2[i];
		std::cout<< vertGroup[idx]<<std::endl;
	}

	return 0;
}