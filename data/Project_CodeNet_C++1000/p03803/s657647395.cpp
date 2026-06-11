#include <iostream>
#include <cmath>
#include <vector>
#include <map>
#include <iomanip>
#include <algorithm>
#include <sstream>
#include <string>
#include <math.h>
#include <set>
using namespace std;
 
int main() {
	ios::sync_with_stdio(false);
	int a,b;
	cin >> a >> b;
	if (a==1 && a!=b) cout << "Alice";
	else if (b==1 && a!=b) cout << "Bob";
	else if (a>b) cout << "Alice";
	else if (a<b) cout << "Bob";
	else cout << "Draw";
}