//Created by Vadim Chernetsov.
#include <iostream>
#include <vector>
using namespace std;
const int size=4000;
bool visited[size][size];
int distances[size][size];
vector<int> graph[size];
int number, diameter;
void dfs(int root, int start, int distance)
{
	//commandsBeforeRecursion.
	visited[root][start]=true;
	distances[root][start]=distance;
	for(int next : graph[start])
	{
		if(!visited[root][next])
		{
			dfs(root, next, distance+1);
		}
	}
	//commandsAfterRecursion.
	return;
}
void usingDFS()
{
	int vertex0, vertex1;
	cin>>number>>diameter;
	for(int i=1; i<number; ++i)
	{
		cin>>vertex0>>vertex1;
		graph[vertex0].push_back(vertex1);
		graph[vertex1].push_back(vertex0);
	}
	for(int point=1; point<=number; ++point)
	{
		dfs(point, point, 0);
	}
	if(diameter%2==0)
	{
		int counter, minValue=4000;
		for(int i=1; i<=number; ++i)
		{
			counter=0;
			for(int j=1; j<=number; ++j)
			{
				if(distances[i][j]>diameter/2)
				{
					++counter;
				}
			}
			minValue=min(minValue, counter);
		}
		cout<<minValue<<endl;
	}
	else
	{
		int counter, minValue=4000, temporaryValue;
		for(int i=1; i<=number; ++i)
		{
			for(int j=1; j<=number; ++j)
			{
				if(distances[i][j]==1)
				{
					counter=0;
					for(int k=1; k<=number; ++k)
					{
						temporaryValue=min(distances[k][i], distances[k][j]);
						if(temporaryValue>diameter/2)
						{
							++counter;
						}
					}
					//cout<<counter<<", ";
					minValue=min(minValue, counter);
				}
			}
		}
		cout<<minValue<<endl;
	}
	return;
}
int main()
{
	usingDFS();
	return 0;
}