#include <iostream>
using namespace std;
int main()
{
	int h, w;
	cin >> h >> w;
	char tab[2*h][w], tmp;
	for(int i = 0; i < h; i++)
		for(int j = 0; j < w; j++)
		{
			cin >> tmp;
			tab[2*i][j] = tmp;
			tab[2*i+1][j] = tmp;
		}
	for(int i = 0; i < 2*h; i++)
	{
		for(int j = 0; j < w; j++)
			cout << tab[i][j];
		cout << "\n";
	}
}