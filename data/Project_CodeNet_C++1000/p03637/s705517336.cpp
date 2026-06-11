#include <cstdio>
#include<iostream>
#include<cmath>
#include<queue>
#include<algorithm>
#include<cstring>
#include<string>
#include<vector>
#define MAXN 5003
using namespace std;




int main(){
    vector<int> a1;
    vector<int> a2;
    vector<int> a4;
    bool flag=1;
    int n;
    cin >> n;
    for(int i=0; i<n; i++){
        int a;
        cin >> a;
        if(a%4 == 0)
            a4.push_back(a);
        else if(a%2 == 0)
            a2.push_back(a);
        else
            a1.push_back(a);
    }

    if(a4.size() + 1 < a1.size()){
        flag = 0;
    }else if(a4.size() < a1.size()){
        if(a2.size() > 0)
            flag = 0;
    }
    if(flag) cout << "Yes" << endl;
    else cout << "No" << endl;


    return 0;
}
