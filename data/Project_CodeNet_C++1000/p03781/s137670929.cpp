#include <iostream>
#include<set>
#include<math.h>
#include<list>
#include<vector>
#include<map>
using namespace std;
#define rep(i, n) for(int i=0;i<n;i++)

int main(){
    int i, num;
    i = 0;num=0;
    int n;
    cin >> n;
    while(i < n){
        num++;
        i += num;
    }
    cout << num << endl;


    return 0;
}