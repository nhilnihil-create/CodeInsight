#include <bits/stdc++.h>
using namespace std;

int main(){
int N;
cin >> N;


for(int i=1;i<=64;i*=2){
    if(i<=N && N < i*2){
        cout << i << endl;
        return 0;
    }
}

return 0;
}