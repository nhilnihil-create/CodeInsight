#include <iostream>

using namespace std;

int main(){
    int N;
    cin>>N;
    int n = 1;
    int m = 1;
    while(n<=N){
        m = n;
        n = n * 2;
    }
    cout<<m<<endl;
}