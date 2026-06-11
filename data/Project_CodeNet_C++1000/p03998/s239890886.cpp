#include <bits/stdc++.h>
using namespace std;
int main(){
	string a, b, c;
	
	cin >> a >> b >> c;
	
	vector <char> va, vb, vc;
	
	int as = a.size(), bs = b.size(), cs = c.size();
	
	for(int i = 0; i < as; i ++){
		va.push_back(a[i]);
	}
	for(int i = 0; i < cs; i ++){
		vc.push_back(c[i]);
	}
	for(int i = 0; i < bs; i ++){
		vb.push_back(b[i]);
	}
	
	char t = 'a';
	
	while(true){
		if(t == 'a'){
			if(va.empty()){
				cout << "A";
				return 0;
			}
			
			t = va.front();
			va.erase(va.begin());
			
		}
		else if(t == 'b'){
			if(vb.empty()){
				cout << "B";
				return 0;
			}
			
			t = vb.front();
			vb.erase(vb.begin());
			
		}
		else{
			if(vc.empty()){
				cout << "C";
				return 0;
			}
			
			t = vc.front();
			vc.erase(vc.begin());
			
		}
		
	}
	
	return 0;
}

