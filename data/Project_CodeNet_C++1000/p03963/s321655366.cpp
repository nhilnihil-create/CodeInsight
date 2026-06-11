#include <iostream>
#include<map>
#include<set>

#include <unordered_map>
#include <algorithm>
#include <vector>
#include <math.h>
using namespace std;

void solver() {
    int n,k;
    cin>>n>>k;
    long long ans=k;
    for(int i=1;i<n;i++)
    {

            ans*=k-1;

    }
    cout<<ans;






}

int main() {
    int n=1;
    //cin >> n;
    while (n--) {
        solver();
    }
}
