#include <iostream>
#include <vector>
using namespace std;
 
int main() {
    int arr[7]={1,2,4,8,16,32,64};
    int N;
    int temp;
    
    cin >> N;
    
    for(int i=0; i < N; i++){
        temp = arr[i];
        if(temp > N){
          temp = arr[i-1];
          break;
        }
    }
    
    cout << temp;
    
    return 0;
}