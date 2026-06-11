#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

int main(){
    int n;
    vector<int> s;
    cin >> n;

    int a;
    int sum = 0;
    for(int i = 0; i < n; i++){
        cin >> a;
        s.push_back(a);
        sum += a;
    }
    sort(s.begin(), s.end());

    if(sum % 10 != 0){
        printf("%d\n", sum);
        return 0;
    }

    for(int i = 0; i < n; i++){
        if(s[i] % 10 != 0){
            printf("%d\n", sum - s[i]);

            return 0;
        }
    }

    printf("0\n");

    return 0;
}