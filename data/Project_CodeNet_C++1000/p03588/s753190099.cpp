#include <iostream>
using namespace std;

int main(){
    int N;
    cin >> N;
    int rank = 0,mi = 2e9;
    for(int i=0;i<N;i++){
        int a,b;
        cin >> a >> b;
        if(rank<a){
            rank = a;
            mi = b; 
        }
    }
    cout << rank+mi << endl;
}