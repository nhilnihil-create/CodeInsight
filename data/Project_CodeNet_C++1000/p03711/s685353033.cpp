#include <iostream>
#include <algorithm>
#include <math.h>
#include <vector>
#include <string>
#include <queue>
#include <map>
#include <utility>
using namespace std;
using ll = long long;
char getGroup (int);
 
int main() {
	int x,y;
	cin >> x >> y;
	if (getGroup(x) == getGroup(y)) cout << "Yes" << endl;
	else cout << "No" << endl;
}

char getGroup(int a)
{
	if(a == 1 || a == 3 || a== 5 || a==7 || a==8 || a==10 || a==12) return 'a';
	else if (a == 4 || a==6 || a== 9 || a==11) return 'b';
	else return 'c';

}
