#include<iostream>
#include<vector>
using namespace std;
int n,m;
int a[200000],b[200000];
vector<int>possible_island;
int binary_search(int key) {
    int left = 0, right = (int)possible_island.size() - 1;
    while (right >= left) {
        int mid = left + (right - left) / 2;
        if (possible_island[mid] == key) return mid;
        else if (possible_island[mid] > key) right = mid - 1;
        else if (possible_island[mid] < key) left = mid + 1;
    }
    return -1;
}
int main(void){
    cin>>n>>m;
    for(int i(0);i<m;i++){
        cin>>a[i]>>b[i];
    }
    for(int i(0);i<m;i++){
        if(b[i] == n)possible_island.push_back(a[i]);
    }
    sort(possible_island.begin(),possible_island.end());
    bool ok(false);
    for(int i(0);i<m;i++){
        if(a[i] == 1 && binary_search(b[i])>=0)ok = true;
    }
    if(ok)cout<<"POSSIBLE"<<endl;
    else cout<<"IMPOSSIBLE"<<endl;
    return 0;
}