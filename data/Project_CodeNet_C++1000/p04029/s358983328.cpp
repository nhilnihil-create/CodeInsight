#include<iostream>
#include <algorithm>
#include<string>
#include <numeric>
#include<math.h>
#include <bits/stdc++.h>
using namespace std;

int main(void) {
    int a,ans=0;
    cin >>a;
    while(a>=0){
        ans+=a;
        a--;
    }

    cout<<ans<<endl;
}
