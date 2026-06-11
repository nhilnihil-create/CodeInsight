#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main(){
    int N;
    cin >> N;
    vector<int> light(N);
    for(int i = 0; i < N; i++){
        int num;
        cin >> num;
        light.at(i) = num - 1 ;
    }

    int count = 0;
    int now = 0;
    while(true){
        if(now == 1){
            cout << count << endl;
            break;
        }
        if(count >= N){
            cout << -1 << endl;
            break;
        }

        count++;
        now = light.at(now);
    }
    
}