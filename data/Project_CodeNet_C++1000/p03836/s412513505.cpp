#include <iostream>
using namespace std;
int main()
{
	int sx, sy, tx, ty, y_diff, x_diff;
    cin >> sx >> sy >> tx >> ty;
    y_diff = ty - sy;
    x_diff = tx - sx;
    for(int i = 0; i < y_diff; i++)
    	cout << "U";
    for(int i = 0; i < x_diff; i++)
    	cout << "R";
    for(int i = 0; i < y_diff; i++)
    	cout << "D";
    for(int i = 0; i < x_diff; i++)
    	cout << "L";
    cout << "L";
    for(int i = 0; i < y_diff+1; i++)
    	cout << "U";
    for(int i = 0; i < x_diff+1; i++)
    	cout << "R";
    cout << "DR";
    for(int i = 0; i < y_diff+1; i++)
    	cout << "D";
    for(int i = 0; i < x_diff+1; i++)
    	cout << "L";
    cout << "U";
}