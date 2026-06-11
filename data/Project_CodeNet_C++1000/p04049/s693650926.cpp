#include <iostream>
#include <vector>
#include <tuple>
using namespace std;
const int maxSize=4000;
bool visited[maxSize][maxSize];
int distances[maxSize][maxSize], amount, diameter;
vector<int> graph[maxSize];
vector<tuple<int, int>> lines;
void fillingGraph()
{
	cin>>amount>>diameter;
	int vertex0, vertex1;
	for(int i=1; i<amount; ++i)
	{
		cin>>vertex0>>vertex1;
		graph[vertex0].push_back(vertex1);
		graph[vertex1].push_back(vertex0);
		lines.push_back(make_tuple(vertex0, vertex1));
	}
	return;
}
void dfs(int root, int firstPoint, int distance)
{
	visited[root][firstPoint]=true;
	for(int secondPoint : graph[firstPoint])
	{
		if(!visited[root][secondPoint])
		{
			dfs(root, secondPoint, distance+1);
		}
	}
	distances[root][firstPoint]=distance;
	return;
}
void usingDfs()
{
	for(int point=1; point<=amount; ++point)
	{
		dfs(point, point, 0);
	}
	//If a diameter of a graph is even, therefore,
	//a center of the diameter will be a point.
	if(diameter%2==0)
	{
		int evenCase=-400, evenNumber;
		for(int i=1; i<=amount; ++i)
		{
			evenNumber=0;
			for(int j=1; j<=amount; ++j)
			{
				if(distances[i][j]<=diameter/2)
				{
					++evenNumber;
				}
			}
			evenCase=max(evenCase, evenNumber);
		}
		cout<<(amount-evenCase);
	}
	//If a diameter of a graph is odd, therefore,
	//a center of the diameter will be a line.
	else
	{
		int oddCase=-400, oddNumber;
		for(auto item : lines)
		{
			oddNumber=0;
			for(int i=1; i<=amount; ++i)
			{
				int temporary=min(distances[i][get<0>(item)], distances[i][get<1>(item)]);
				if(temporary<=diameter/2)
				{
					++oddNumber;
				}
			}
			oddCase=max(oddCase, oddNumber);
		}
		cout<<(amount-oddCase);
	}
	return;
}
int main()
{
	fillingGraph();
	usingDfs();
	return 0;
}