#include <iostream>
#include<bits/stdc++.h>
#include <string>
#define loop(i,n) for(int i=0;i<(int)n;i++)

using namespace std;


int main()
{

int n;
cin>>n;

int arr[n];
loop(i,n) cin>>arr[i];

int mini;
int ans=INT_MAX;

for(int i=-100;i<=100;i++){
        mini=0;

    for(int j=0;j<n;j++){

      mini=mini+((arr[j]-i)*(arr[j]-i));

    }

    ans=min(ans,mini);

}

cout<<ans;
}


