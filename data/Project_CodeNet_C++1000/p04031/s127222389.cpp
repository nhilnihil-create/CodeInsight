#include <bits/stdc++.h>

using namespace std;
int main()
{
    int N;
    int a[110];
    int ave=0;
    cin >> N;
    for(int i=0; i<N; i++){
        cin >> a[i];
        ave+=a[i];
    }
    ave/=N;

    int sum1=0,sum2=0;
    for(int i=0; i<N; i++){
        sum1+=pow((a[i]-ave),2);
        sum2+=pow((a[i]-(ave+1)),2);
    }

    if(sum1<sum2){
        cout << sum1 << endl;
    }
    else cout << sum2 << endl;

    return 0;
}
