#include<iostream>
#include<math.h>

using namespace std;

int main(){
    int N;
    cin >> N;
    int a[N], i, j, sum=0, avg, min;
    double b[3], cost[3];

    for (i=0; i<N; i++){
        cin >> a[i];
        sum += a[i];
    }
    for (j=0; j<3; j++){
        cost[j] = 0;
    }

    avg = sum / N;
    for (i=0; i<N; i++){
        b[0] = (double)(a[i] - avg);
        b[1] = (double)(a[i] - (avg + 1));
        b[2] = (double)(a[i] - (avg - 1));
        for (j=0; j<3; j++){
            cost[j] +=pow(b[j], 2);
        }
    }

    min = cost[0];
    for (i=1; i<3; i++){
        if (cost[i] < min){
            min = cost[i];
        }
    }
    cout << min;
    return 0;
}