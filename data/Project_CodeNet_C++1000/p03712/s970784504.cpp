#include <bits/stdc++.h>
using namespace std;

int main(void)
{
	int H, W;
  	cin >> H >> W;
  	for (int i=0; i < W + 2; i++)
    	cout << '#';
  	cout << endl;
  	for (int i=0; i < H; i++)
    {
      string str;
      cout << '#';
      cin >> str;
      cout << str;
      cout << '#' << endl;
    }
    for (int i=0; i < W + 2; i++)
    	cout << '#';
   	cout << endl;
}