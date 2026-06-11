#include <iostream>
#include <vector>
#include <set>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include <iomanip>
#include <numeric>
#include <queue>
#include <cmath>
using namespace std;

int main() {
	string s;
  	cin >> s;
  	if (s.size() >= 4 && s[0] == 'Y' && s[1] == 'A' && s[2] == 'K' && s[3] == 'I') 
      	cout << "Yes" << endl;
    else
      	cout << "No" << endl;
}


