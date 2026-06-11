#include <stdio.h>
#include <string>
#include <iostream>
#include <iomanip>
#include <map>
#include <algorithm>
using namespace std;

int main(void){
    int n;
    int low[100005];
    cin >> n;
    for(int i=1; i<=n; i++)cin >> low[i];
    int count=0;
    for(int i=1; i<=n; i++){
        if(low[i]==i){
            count++;
            i++;
        }
    }
    cout << count << endl;
    return 0;
}