#include <iostream>
#include <vector>
using namespace std;
typedef vector<int> vi;
const int size=4000;
vi graph[size];
int lineDistances[size][size];
bool visited[size][size];
vi vertexA, vertexB;
int number, diameter;
void dfs(int root, int start, int distanceInLines)
{
	//commandsBeforeVisitRecursion.
	visited[root][start]=true;
	lineDistances[root][start]=distanceInLines;
	for(int next : graph[start])
	{
		if(!visited[root][next])
		{
			dfs(root, next, distanceInLines+1);
		}
	}
	//commandsAfterVisitRecursion.
	return;
}
void usingDFS()
{
	cin>>number>>diameter;
	int vertex0, vertex1;
	for(int i=1; i<number; ++i)
	{
		cin>>vertex0>>vertex1;
		graph[vertex0].push_back(vertex1);
		graph[vertex1].push_back(vertex0);
		vertexA.push_back(vertex0);
		vertexB.push_back(vertex1);
	}
	for(int vertex=1; vertex<=number; ++vertex)
	{
		dfs(vertex, vertex, 0);
	}
	if(diameter%2==0)
	{
		int minimum=4000;
		for(int i=1; i<=number; ++i)
		{
			int counter=0;
			for(int j=1; j<=number; ++j)
			{
				if(lineDistances[i][j]>diameter/2)
				{
					++counter;
				}
			}
			minimum=min(minimum, counter);
		}
		cout<<minimum<<endl;
	}
	else
	{
		int dotA, dotB, tempMaxDist, minimum=4000;
		for(int i=0; i<vertexA.size(); ++i)
		{
			int counter=0;
			dotA=vertexA[i];
			dotB=vertexB[i];
			for(int j=1; j<=number; ++j)
			{
				tempMaxDist=min(lineDistances[j][dotA], lineDistances[j][dotB]);
				if(tempMaxDist>diameter/2)
				{
					++counter;
				}
			}
			minimum=min(minimum, counter);
		}
		cout<<minimum<<endl;
	}
	return;
}
int main()
{
    usingDFS();
	return 0;
}