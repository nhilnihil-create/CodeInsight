#include<iostream>
#include<set>

using namespace std;

int main()
{
	string s;
	cin >>s;
	
	int mn = 1e9;
	for(auto c : s){
		string cur = s;
		int stps = 0;
		
		while(true){
			
			set<char> st;
			for(auto ch : cur)
				st.insert(ch);
			if(st.size() == 1){
				break;
			}
			
			string nxt = "";
			++stps;
			for(int i = 0; i < cur.size() - 1; ++i){
				if(cur[i] == c || (i + 1 < cur.size() && cur[i + 1] == c)){
					nxt += c; 
				}
				else{
					nxt += cur[i];
				}
			}
			
			cur = nxt;
		}
		mn = min(mn, stps);
	}
	
	cout <<mn <<'\n';
	return 0;
}
