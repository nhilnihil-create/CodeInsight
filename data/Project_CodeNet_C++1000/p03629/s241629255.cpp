#include <iostream>
#include <string>
#include <vector>
using namespace std;

int next_index[26][200010];

int main() {
	string A;
	cin >> A;
	A="?"+A;
	vector<string> v(26, "a");
	for(int i=0; i<26; ++i){
	    v[i][0] += i;
	}
	for(int p=A.size()-2; p>=0; --p){
	    int now=0;
	    for(int i=1; i<26; ++i){
	        if(v[i].size()<v[now].size()) now=i;
	    }
	    v[A[p+1]-'a']=A[p+1]+v[now];
	}
	int ans=0;
	for(int i=1; i<26; ++i){
	    if(v[i].size()<v[ans].size()) ans=i;
	}
	cout << v[ans] << endl;
	return 0;
}
