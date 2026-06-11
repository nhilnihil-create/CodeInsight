#include <bits/stdc++.h>
#define rep(i , n) for (int i = 0; i < (int)(n); i++)
const int INF = 1<<29;
using namespace std;
using ll = long long;
int main(){
	string s , a = "";
	cin>>s;
	for(auto i : s){
        if(i=='B'){
            if(a.size()){
                a.pop_back();
            }
        }
	    else{
            a.push_back(i);
        }
    }
	cout << a << endl;
}