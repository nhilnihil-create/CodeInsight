#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include<set>
#include<map>
using namespace std;


int main() {
    vector<int> v(3);
    for(int i = 0; i < 3; i++){
        cin >> v[i];
    }
    sort(v.begin(),v.end());
    if(v[0]+v[1] == v[2]){
        cout << "Yes";
    }
    else
    {
        cout << "No";
    }
    
}
