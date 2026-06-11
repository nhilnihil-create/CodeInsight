#include <iostream>
#include <vector>
#include <tuple>
using namespace std;
const int maxSize=4000;
bool visited[maxSize][maxSize];
int distances[maxSize][maxSize], amount, diameter;
vector<int> graph[maxSize];
vector<tuple<int, int>> connectedDots;
template<typename Type>
void showContent(Type input)
{
	for(auto item : input)
	{
		cout<<get<0>(item)<<" : "<<get<1>(item)<<endl;
	}
	return;
}
void fillingGraph()
{
	cin>>amount>>diameter;
	int vertex0, vertex1;
	for(int i=1; i<amount; ++i)
	{
		cin>>vertex0>>vertex1;
		graph[vertex0].push_back(vertex1);
		graph[vertex1].push_back(vertex0);
		connectedDots.push_back(make_tuple(vertex0, vertex1));
	}
	return;
}
void dfs(int root, int current, int distance)
{
	visited[root][current]=true;
	for(int next : graph[current])
	{
		if(!visited[root][next])
		{
			dfs(root, next, distance+1);
		}
	}
	distances[root][current]=distance;
	return;
}
void usingDfs()
{
	for(int point=1; point<=amount; ++point)
	{
		dfs(point, point, 0);
	}
	if(diameter%2==0)
	{
		int evenCounter=0, evenMinimum=4000;
		for(int i=1; i<=amount; ++i)
		{
			evenCounter=0;
			for(int j=1; j<=amount; ++j)
			{
				if(distances[i][j]>diameter/2)
				{
					++evenCounter;
				}
			}
			evenMinimum=min(evenMinimum, evenCounter);
		}
		cout<<evenMinimum;
	}
	if(diameter%2!=0)
	{
		int oddCounter=0, oddMinimum=4000;
		for(auto item : connectedDots)
		{
			oddCounter=0;
			for(int i=1; i<=amount; ++i)
			{
				int temporary=min(distances[get<0>(item)][i], distances[get<1>(item)][i]);
				if(temporary>diameter/2)
				{
					++oddCounter;
				}
			}
			oddMinimum=min(oddMinimum, oddCounter);
		}
		cout<<oddMinimum;
	}
	return;
}
int main()
{
	fillingGraph();
	usingDfs();
	//showContent(connectedDots);
	return 0;
}