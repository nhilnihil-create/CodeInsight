#include<iostream>
#include<fstream>
#include<string>
#include<cmath>
#include<queue>
#include<vector>
using namespace std;

int main(){
	string n,r;
	char b;
	int h,w;
	cin >> h;
	cin >> w;
	
	r="snuke";

    
    for (int j=0;j<h;j++){
    	for(int i=0;i<w;i++){
			cin >> n;
    		if (r==n){
    			b = 'A'+i;
    			cout << b << j+1 << endl;
    			
    			
			}
		}
	}

	return 0;
}