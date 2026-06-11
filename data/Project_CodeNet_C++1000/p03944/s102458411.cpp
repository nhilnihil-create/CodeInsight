#include <bits/stdc++.h>
using namespace std;

int main(){
	int w, h, n;
	cin >> w >> h >> n;
	vector<vector<int>> data(n, vector<int>(3));
	for(int i=0; i<n; i++){
		for(int j=0; j<3; j++){
			cin >> data.at(i).at(j);
		}
	}
	vector<vector<int>> ori(w, vector<int>(h));
	for(int i=0; i<n; i++){
		if(data.at(i).at(2)==1){
			for(int j=0; j<data.at(i).at(0); j++){
				for(int k=0; k<h; k++){
					ori.at(j).at(k)++;
				}
			}
		}
		if(data.at(i).at(2)==2){
			for(int j=data.at(i).at(0); j<w; j++){
				for(int k=0; k<h; k++){
					ori.at(j).at(k)++;
				}
			}
		}
		if(data.at(i).at(2)==3){
			for(int j=0; j<data.at(i).at(1); j++){
				for(int k=0; k<w; k++){
					ori.at(k).at(j)++;
				}
			}
		}
		if(data.at(i).at(2)==4){
			for(int j=data.at(i).at(1); j<h; j++){
				for(int k=0; k<w; k++){
					ori.at(k).at(j)++;
				}
			}
		}
	}
	int num=0;
	for(int i=0; i<w; i++){
		for(int j=0; j<h; j++){
			if(ori.at(i).at(j)==0){
				num++;
			}
		}
	}
	cout << num << endl;
}
