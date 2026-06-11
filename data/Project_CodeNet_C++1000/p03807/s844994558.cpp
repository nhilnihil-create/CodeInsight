#include<iostream>

using namespace std;

int arr[2];

int main(){
    int  N;
    cin >> N;
    for(int i=1 ; i<=N; i++){
        int num ;
        cin >> num;
        arr[num%2]++;
    }
    if(arr[1] % 2 == 1){
        cout << "NO" << endl;
    } else{
        cout << "YES" << endl;
    }
}