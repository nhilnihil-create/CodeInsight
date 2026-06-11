#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    vector<int> vec;
    for(int i=0; i<2*n ; i++){
        int a;
        cin >> a;
        vec.push_back(a);
    }
    sort(vec.begin(),vec.end());
    int cnt = 0;
    for(int i=0; i<2*n-1; i+=2){
        cnt += min(vec[i],vec[i+1]);
//        cout << vec[i] << " " << vec[i+1] << endl;
//        cout << cnt <<endl;
    }
    cout << cnt <<endl;
    return 0;
}