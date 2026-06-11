#include <iostream>
#define ll long long
using namespace std;
int arr[100005];
int main(){
    ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL);
    int n, m, maxi=0, maxs=0;
    cin  >> n;
    for(int i=1; i<=n; i++){
        cin >> m;
        arr[m]++;
        arr[m-1]++;
        arr[m+1]++;
        if(maxi<m){
            maxi=m;
        }
    }
    for(int i=1; i<=maxi+1; i++){
        if(maxs<arr[i]){
            maxs=arr[i];
        }
    }
    cout << maxs << endl;
    return 0;
}