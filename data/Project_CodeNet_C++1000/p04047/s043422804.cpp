#include <iostream>
#include<vector>
#include <bits/stdc++.h>
using namespace std;


int main(int argc, char** argv) {

    int n;
	cin>>n;
    vector <int> v;
    for (int i =0; i<2*n;i++)
    {int x;
        cin>>x;
        v.push_back(x);}
    sort(v.begin(), v.end());
    int max=0;
    for (int i = 0; i < v.size(); i=i+2)
    {
        max=max+min(v[i], v[i+1]);
    }
cout<<max;
    return 0;
}
