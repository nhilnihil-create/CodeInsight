#include <iostream>
#include <vector>
#include <map>
using namespace std;

int main() {
	int N; cin >> N;
	map<int, vector<int>> mp;
	int get[100010];
	int a, b;
	for(int i=1; i<N; ++i){
	    cin >> a >> b;
	    mp[a].push_back(b);
	    mp[b].push_back(a);
	    get[i]=0;
	}
	get[1]=1;
	get[N]=2;
	int F=0, S=0;
	vector<int> B{1}, Bnext, W{N}, Wnext;
	while(F+S+2!=N){
	    for(int i=0; i!=B.size(); ++i){
	        for(int j=0; j!=mp[B[i]].size(); ++j){
	            if(!get[mp[B[i]][j]]){
	                ++F;
	                get[mp[B[i]][j]]=1;
	                Bnext.push_back(mp[B[i]][j]);
	            }
	        }
	    }
	    for(int i=0; i!=W.size(); ++i){
	        for(int j=0; j!=mp[W[i]].size(); ++j){
	            if(!get[mp[W[i]][j]]){
	                ++S;
	                get[mp[W[i]][j]]=2;
	                Wnext.push_back(mp[W[i]][j]);
	            }
	        }
	    }
	    B=Bnext; Bnext.erase(Bnext.begin(), Bnext.end());
	    W=Wnext; Wnext.erase(Wnext.begin(), Wnext.end());
	}
	if(F>S) cout << "Fennec" << endl;
	else cout << "Snuke" << endl;
	return 0;
}
