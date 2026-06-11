#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <cmath>

using namespace std;

void agc_a_prefix_and_suffix(void) {
	int n;
	string s, t;
	cin >> n >> s >> t;
	

	int match_num = 0;
	for (int i = 1; i <= n; i++){
		string s_sub = s.substr(s.size()-i,i);
		string t_sub = t.substr(0, i);
		if (s_sub == t_sub) {
			match_num = i;
		}
		
	}

	int out_length = s.size() + t.size() - match_num;

	cout << out_length << endl;

}

int main()
{
    agc_a_prefix_and_suffix();
    return 0;
}