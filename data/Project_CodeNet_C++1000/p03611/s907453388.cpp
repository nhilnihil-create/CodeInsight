#include <iostream>
using namespace std;

int main(){
    int N;
    cin >> N;
    int a[100010]={0};
    int x;
    int i,j;
    int ans=1;
    int max=1;

    for(i=0; i<N; i++){
        cin >> x;
        if(x!=0){
            for(j=-1; j<2; j++){
                a[x+j]++;
            }
        }
        else{
            a[0]++;
            a[1]++;
        }
        if(x>max) max=x;
    }

    for(i=0; i<=100000; i++){
        if(ans<a[i]) ans=a[i];
    }

    cout << ans << endl;

    return 0;
}