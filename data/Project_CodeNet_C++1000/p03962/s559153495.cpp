#include <iostream>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <list>
#include <set>
#include <queue>
#include <iterator>
#include <bitset>
#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
#define ll             long long
#define _              ios_base::sync_with_stdio(0);cin.tie(0);
#define loop           for(i=0;i<n;i++)
#define pb             push_back
#define tc()           int t;cin>>t;while(t--)

using namespace std;

ll i,j,temp;

int main()
{_

    set<int> myset;
    int x=3,i,k;
    //cin>>x;
    for(i=0;i<x;i++){
        cin>>k;
        myset.insert(k);
    }
    cout<<myset.size()<<endl;
	return 0;
}