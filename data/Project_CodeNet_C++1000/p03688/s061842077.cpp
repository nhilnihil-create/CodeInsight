#include<iostream>

using namespace std;

int cats[100005];

int main(){
    int N;
    cin >> N;

    int max = 0, min = 100005;
    for(int i=1; i<=N; i++){
        int a;
        cin >> a;

        cats[a]++;
        if(a > max) max = a;
        if(a < min) min = a;
    }

    if(max - min > 1) cout << "No" << endl;
    else if(max == min){
        if(max == N-1 || 2*max <= N) cout << "Yes" << endl;
        else cout << "No" << endl;
    }else if(max - min == 1){
        if(cats[min] + 1 <= max && max <= cats[min] + (cats[max]/2)) cout << "Yes" << endl;
        else cout << "No " << endl;
    }
}