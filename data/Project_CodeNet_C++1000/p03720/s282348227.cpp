// バケット法による解
#include <iostream>
using namespace std;

int main() {
    int N,M;
    cin >> N >> M;
    int b[110];
    for(int i = 0; i< M*2;++i)  cin >> b[i];
    int app[110] = {0};
    for(int i = 0; i< M*2;++i){
      app[b[i]]++;
    }
    for(int i = 1;i<=N;++i){
      cout << app[i] << endl;
    }
}
