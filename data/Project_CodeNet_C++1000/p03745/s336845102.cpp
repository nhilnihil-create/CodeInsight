#include <iostream>
#include <cstring>
#include <cmath>
#include <algorithm>
#define ll long long
using namespace std;

ll arr[100005];
int memo[100005];

int main()
{
    int n;
    cin >> n;
    
    memset (memo,0,sizeof(memo));
    int ans = 1;
    int track = 2;
    //if track = 0 it means that it is increasing, track = 1 means it is decreasing track = 2 is neutral
    for (int i = 1; i <= n; i++){
        cin >> arr[i];
        if (i >= 2){
          if (track == 2 && arr[i] != arr[i-1]){
            if (arr[i] > arr[i-1])
              track = 0;
            else
              track = 1;
          }
          else if (track != 2){
            if (arr[i] > arr [i-1] && track == 1){
              ans++;
              track = 2;
            }
            else if (arr[i] < arr [i-1] && track == 0){
              ans++;
              track = 2;
            }
          }
        }
    }
    
    
    
    cout << ans << endl;

    return 0;
}