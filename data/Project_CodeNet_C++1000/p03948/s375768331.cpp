#include<iostream>
using namespace std;

int main()
{
    int n, t;
    cin >> n >> t;
    int a[100010];
    int max_val[100010];
    int min_val[100010];
    max_val[n + 1] = 0;
    min_val[0] = 2000000000;
    int delta_val[100010];
    delta_val[0] = 0;
    int number = 0;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
        min_val[i] = min(min_val[i - 1], a[i]);
    }
    for(int i = n; i >= 1; i--){
        max_val[i] = max(max_val[i + 1], a[i]);
    }
    for(int i = 1; i <= n; i++){
        if(a[i] - min_val[i] > delta_val[i - 1]){
            number = 1;
        }
        if(a[i] - min_val[i] == delta_val[i - 1]){
            number++;
        }
        delta_val[i] = max(delta_val[i - 1], a[i] - min_val[i]);
    }
    cout << number << endl;
    return 0;
}