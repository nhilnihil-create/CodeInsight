#include <iostream>
#include <vector>
using namespace std;

int main() {
	int row, col;
	cin>> row >> col;
	int N;
	cin >> N;
	vector<int>arr;
	int mat[row][col];
	int x;
	for (int i=0; i<N; i++){
		cin >> x;
		for(int j=0; j<x; j++){
			arr.push_back(i+1);
		}
	}
	
	//for (int i=0; i<arr.size(); i++){
	//	cout << arr[i];
	//}cout << '\n';
	
	for (int i=0; i<row; i++){
		if (i%2==0){
			for (int j=0; j<col; j++){
				mat[i][j]=arr[j+i*col];
			}	
		}
		else{
			for (int j=0; j<col; j++){
				mat[i][j]=arr[col-1-j+i*col];
			}
		}
	}
	for (int i=0; i<row; i++){
		for (int j=0; j<col; j++){
			cout << mat[i][j] << ' ';
		}
		cout <<'\n';
	}
}