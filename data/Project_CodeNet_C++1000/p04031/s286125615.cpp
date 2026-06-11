#include<iostream>
using namespace std;

int getCost(int arr[], int N, int target){
	int cost = 0;
    for(int i=0; i<N; i++){
        int diff = arr[i]-target;
    	cost += diff*diff;
    }
  	return cost;
}
int main(){
  int N;
  cin >> N;
  int arr[N];
  int min = 200;
  int max = -200;
  int minCost;
  for(int i=0; i<N; i++){
  	cin >> arr[i];
    if(arr[i] < min){
    	min = arr[i];
    }else if(arr[i] > max){
    	max = arr[i];
    }
  }
  minCost = getCost(arr, N, min);
  for(int i=min+1; i<=max; i++){
  	int cost = getCost(arr, N, i);
    if( cost < minCost ){
      minCost = cost;
    }
  }
  cout << minCost << '\n';
}