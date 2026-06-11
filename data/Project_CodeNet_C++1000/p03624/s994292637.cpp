#include <iostream>
#include <vector>
#include <string>
#include <set>

using namespace std;

int main(){
  	string s;
  	string abc = "abcdefghijklmnopqrstuvwxyz";
  	cin >> s;
  	vector<int> num(26);
  	int N = s.size();
  	for(int i=0;i<N;i++){
      	int index = abc.find_first_of(s[i]);
      	num[index] = 1;
    }
  	int i=0;
  	for(i=0;i<26;i++){
      	if(num[i]==0) break;
    }
  	if(i == 26) cout << "None" << endl;
    else cout << abc[i] << endl;
}