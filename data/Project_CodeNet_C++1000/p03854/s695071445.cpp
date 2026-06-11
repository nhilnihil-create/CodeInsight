#include<bits/stdc++.h>
using namespace std;

int main() {
  	string s;
  	string arr[] = {"dreamer", "dream", "eraser", "erase"};
  	regex re("[bcfghijklnopqtuvwxyz]");
  	smatch m;
  	cin >> s;
  	if (regex_search(s, m, re)) {
     	cout << "NO" << endl;
      	return 0;
    }
  	int i = 0;
  	while (true) {
      	if(s.size() == 0) {
         	break; 
        }
      	int pos = s.rfind(arr[i]);
      	if(((pos + arr[i].size()) == s.size()) && pos >= 0) {
            s = s.erase(pos, arr[i].size());
            i = 0;
            continue;
        }
      	i++;
      	if (i > 3) {
            cout << "NO" << endl;
            return 0;
        }
    }
  
  	cout << "YES" << endl;
	return 0;  
}