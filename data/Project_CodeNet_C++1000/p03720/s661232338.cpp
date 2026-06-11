#include <iostream>
using namespace std;
int main(void){

int N, M, a, b, i;

cin >> N >> M;

int c[N];

for(i = 0; i < N + 1; i++){
    c[i] = 0;
}

for(i = 0; i < M; i++){
    
    cin >> a >> b;
    
    c[a] = c[a] + 1;
    
    c[b] = c[b] + 1;
    
}

for(i = 1; i <= N; i++){
    cout << c[i] << endl;
}
    
}
