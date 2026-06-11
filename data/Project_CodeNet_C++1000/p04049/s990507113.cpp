#include <iostream>
#include <stack>
#include <vector>
using namespace std;
const int size=4000;
bool visited[size][size];
int distances[size][size];
vector<int> graph[size];
int amount, diameter;
void fillingGraph()
{
	cin>>amount>>diameter;
	int vertex0, vertex1;
	for(int i=1; i<=amount; ++i)
	{
		cin>>vertex0>>vertex1;
		graph[vertex0].push_back(vertex1);
		graph[vertex1].push_back(vertex0);
	}
	return;
}
void dfs(int root, int first, int distance)
{
	stack<int> stack;
	stack.push(first);
	distances[root][first]=distance;
	while(!stack.empty())
	{
		first=stack.top();
		stack.pop();
		visited[root][first]=true;
		for(int second : graph[first])
		{
			if(!visited[root][second])
			{
				stack.push(second);
				distances[root][second]=distances[root][first]+1;
			}
		}
	}
	return;
}
void usingDFS()
{
	for(int point=1; point<=amount; ++point)
	{
		dfs(point, point, 0);
	}
	if(diameter%2==0)
	{
		int counterEven, minimumEven=4000;
		for(int i=1; i<=amount; ++i)
		{
			counterEven=0;
			for(int j=1; j<=amount; ++j)
			{
				if(distances[i][j]>diameter/2)
				{
					++counterEven;
				}
			}
			minimumEven=min(minimumEven, counterEven);
		}
	cout<<minimumEven<<endl;
	}
	if(diameter%2!=0)
	{
		int counterOdd, minimumOdd=4000, temporary;
		for(int i=1; i<=amount; ++i)
		{
			for(int j=1; j<=amount; ++j)
			{
				if(distances[i][j]==1)
				{
					counterOdd=0;
					for(int k=1; k<=amount; ++k)
					{
						temporary=min(distances[k][i], distances[k][j]);
						if(temporary>diameter/2)
						{
							++counterOdd;
						}
					}
					minimumOdd=min(minimumOdd, counterOdd);
				}
			}
		}
	cout<<minimumOdd<<endl;
	}
	return;
}
int main()
{
	fillingGraph();
	usingDFS();
	return 0;
}