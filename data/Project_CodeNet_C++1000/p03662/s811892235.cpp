#include<iostream>
#include<stack>
#include<deque>
#include<list>
#define MAX 100002
#define REP(i,n) for(int i=0;i<(n);i++)
#define WHITE 0
#define GRAY 1
#define BLACK 2
#define NULL -1
using namespace std;

list<int> lst[MAX];
//int M[MAX][MAX] = {};
int parent[MAX] = {};
int color[MAX] = {};

//0:root
void func()
{
	int Color[MAX];
	REP(i, MAX)
	{
		Color[i] = WHITE;
		parent[i] = NULL;
	}

	parent[1] = 1;

	stack<int> stk;
	stk.push(1);
	while (!stk.empty())
	{
		int top = stk.top();
		stk.pop();
		for (auto itr : lst[top])
		{
			if (itr == top)continue;
			else
			{
				if (Color[itr] == WHITE)
				{
					stk.push(itr);
					parent[itr] = top;
					Color[itr] = GRAY;
				}
			}
		}
		Color[top] = BLACK;
	}
}
void func2()
{
	int Color[MAX];
	REP(i, MAX)
	{
		Color[i] = WHITE;
	}
	stack<int> stk;
	stk.push(1);
	while (!stk.empty())
	{
		int top = stk.top();
		stk.pop();
		for (auto itr : lst[top])
		{
			if (itr == top)continue;
			else
			{
				if (Color[itr] != BLACK)
				{
					if (color[itr] == GRAY)
					{
						color[itr] = color[top];
						stk.push(itr);
						Color[itr] = GRAY;
					}
					else
					{
						stk.push(itr);
						Color[itr] = GRAY;
					}
				}
			}
		}
		Color[top] = BLACK;
	}
}

int main()
{
	int N;
	cin >> N;
	//7->index1先手黒7後手白
	REP(i, N-1)
	{
		int t1, t2;
		cin >> t1 >> t2;
		lst[t2].push_back(t1);
		lst[t1].push_back(t2);
	}
	REP(i, MAX)
	{
		color[i] = GRAY;
	}

	color[1] = BLACK;
	color[N] = WHITE;

	func();

	deque<int> deq;

	int p = parent[N];
	//cout << N << "->";
	while (true)
	{
		if (p == 1)
		{
		//	cout << p << endl;
			break;
		}
		deq.push_back(p);
		//cout << p << "->";
		p = parent[p];
	}
	/*
	for (auto itr : deq)
	{
		cout << itr << " ";
	}
	cout <<"tes" <<endl;
	*/

	while (true)
	{
		//1
		if (deq.empty())break;
		int back = deq.back();
		deq.pop_back();
		color[back] = BLACK;
		
		//N
		if (deq.empty())break;
		int front = deq.front();
		deq.pop_front();
		color[front] = WHITE;
	}
	func2();
	int S = 0;
	int F = 0;
	REP(i, N+1)
	{
		if (i == 0)continue;
		else
		{
			if (color[i] == BLACK)
			{
				//cout << i << "B" << endl;
				F++;
			 }
			else
			{
				//cout << i << "W" << endl;
				S++;
			}
		}
	}
	if (S >= F)cout << "Snuke" << endl;
	else cout << "Fennec" << endl;
	//cout << "F:S=" << F << ":" << S << endl;
	return 0;
}