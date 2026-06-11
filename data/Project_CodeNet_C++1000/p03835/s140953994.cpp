// #include <bits/stdc++.h>
#include<iostream>
#include<vector>
#include <bits/stdc++.h>
using namespace std;

int main() {
    int k, s;
    cin >> k >> s;
    int x=0,y=0,z=0;
    int cnt=0;
    for (int x = 0; x <=k ; x++) {
        for(int y=0;y<=k; y++){
            z=s-x-y;
            if (z>=0 && z<=k){
                cnt++;
                // cout<<x<<y<<z<<endl;
            }
        }
    }
    cout<<cnt<<endl;
    return 0;

}