#include<bits/stdc++.h>
using namespace std;

int main()
{
    long int n;
    cin >> n;

    long long int input;
    vector<long long int>vec;

    for(long int i = 0; i < n; i++){
        cin >> input;
        vec.push_back(input);
    }
    sort(vec.begin(), vec.end());
    reverse(vec.begin(), vec.end());

    long long int a = 0, b = 0, c = 0, area_1 = 0, area_2 = 0;
    int cnt = 0;

    for(long int i = 0; i < n; i++){
        if((vec[i] == vec[i+3] || vec[i] == vec[i+1]) && vec[i] > a){
            a = vec[i];
        }
        if(vec[i] == vec[i+3] && vec[i] > c){
            c = vec[i];
        }
        if((vec[i] == vec[i+3] || vec[i] == vec[i+1]) && vec[i] < a && vec[i] > b)
            b = vec[i];
    }

    area_1 = a*b;
    area_2 = c*c;

    if(area_1>area_2)
        cout << area_1;
    else
        cout << area_2;
    return 0;
}
