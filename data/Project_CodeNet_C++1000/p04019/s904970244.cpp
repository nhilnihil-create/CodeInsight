#include <iostream>
#include <math.h>
#include <algorithm>
#include <string>
#include <map>
#include <vector>
#include <cmath>

using namespace std;

void agc_a_wanna_go_back_home(void) {
	string s;
	cin >> s;
	int s_cnt = 0, e_cnt = 0, n_cnt = 0, w_cnt = 0;
	for (int i = 0; i < s.size(); i++) {
		switch (s[i]) {
		case 'N': {
			n_cnt++;
			break;
		}
		case 'W': {
			w_cnt++;
			break;
		}
		case 'S': {
			s_cnt++;
			break;
		}
		case 'E': {
			e_cnt++;
			break;
		}
		}
	}
	if ((e_cnt > 0) && (w_cnt == 0))      cout << "No" << endl;
	else if ((e_cnt == 0) && (w_cnt > 0)) cout << "No" << endl;
	else if ((s_cnt > 0) && (n_cnt == 0)) cout << "No" << endl;
	else if ((s_cnt == 0) && (n_cnt > 0)) cout << "No" << endl;
	else                                  cout << "Yes" << endl;
}

int main()
{
    agc_a_wanna_go_back_home();
    return 0;
}