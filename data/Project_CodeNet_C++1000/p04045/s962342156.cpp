#include<iostream>
#include<vector>
using namespace std;

int main(){
    int N, K;
    vector<int> D(10,0);
    cin >> N >> K;
    int d;
    for(int i=0; i<K; i++){
        cin >> d;
        D[d] = 1;
    }
    for(int i=N; i<100000; i++){
        bool flag = true;
        int tmp = i;
        while(tmp!=0){
            if(D[tmp%10] == 1){
                flag = false;
                break;
            }
            tmp /= 10;
        }
    
        if(flag){
            cout << i << endl;
            break;
        }
    }
    return 0;
}