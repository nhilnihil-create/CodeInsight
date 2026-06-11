#include <iostream>
using namespace std;

int main(){
    int N;
    cin >> N;
    int a;
    int i;
    int check[9]={0};
    for(i=0; i<N; i++){
        cin >> a;
        if(a<400) check[0]++;
        else if(a<800) check[1]++;
        else if(a<1200) check[2]++;
        else if(a<1600) check[3]++;
        else if(a<2000) check[4]++;
        else if(a<2400) check[5]++;
        else if(a<2800) check[6]++;
        else if(a<3200) check[7]++;
        else check[8]++;
    }

    int count=0;
    for(i=0; i<8; i++){
        if(check[i]>0) count++;
    }

    int max,min;
    min=count;
    if(min==0) min=1;
    max=count+check[8];

    cout << min << ' ' << max << endl;

    return 0;
}