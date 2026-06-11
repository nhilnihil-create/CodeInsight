#include <iostream>
using namespace std;

int main(){
    int N;
    cin >> N;
    int *p=new int[N+1];
    for(int i=1;i<=N;i++) cin >> p[i];

    int cnt=0;
    for(int i=1;i<=N-1;i++){
        if(p[i]==i){
            p[i+1]=p[i];
            cnt++;
        }
    }
    if(p[N]==N) cnt++;

    cout << cnt << endl;

    delete[] p;
    return 0;
}