#include <iostream>
using namespace std;

int main()
{
    int a,b,c,N=101;
    cin >> a >> b >> c;

    int color[N] = {};
    color[a]++;
    color[b]++;
    color[c]++;

    int sum=0;
    for(int i=1; i<N; i++){
        if(color[i] > 0){
            sum++;
        }
    }

    cout << sum;
}


