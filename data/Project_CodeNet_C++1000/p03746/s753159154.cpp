#include <iostream>
#include <vector>
#include <map>
#include <deque>
using namespace std;

map<int, vector<int>> mp;
deque<int> d;
bool pass[100010];
int main() {
	int N, M, a, b; cin >> N >> M;
	for(int i=0; i<M; ++i){
	    cin >> a >> b;
	    mp[a].push_back(b);
	    mp[b].push_back(a);
	}
	pass[1]=true;
	d.push_back(1);
	for(int p=0; p<2; ++p){
	    int now=1;
	    bool flag=true;
	    while(flag){
	        flag=false;
	        for(int i=0; i<mp[now].size(); ++i){
	            if(!pass[mp[now][i]]){
	                now=mp[now][i];
	                if(p==0) d.push_front(now);
	                else d.push_back(now);
	                pass[now]=true;
	                flag=true;
	                break;
	            }
	        }
	    }
	}
	cout << d.size() << endl;
	for(int i=0; i<d.size(); ++i){
	    cout << d[i];
	    if(i+1<d.size()) cout << ' ';
	}
	return 0;
}
