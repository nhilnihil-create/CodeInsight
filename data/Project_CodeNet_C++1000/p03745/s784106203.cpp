#include <bits/stdc++.h>
using namespace std;

#define ll long long
#define ull unsigned long long 
#define endl '\n'
#define pii pair<int, int>
#define all(a) a.begin(),a.end()

int main(){
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; ++i)
        cin >> a[i];

    int count=0;
    for(int i=0; i<n; ++i){
        if(a[i]==a[i+1])
            continue;

        if(a[i]<a[i+1]){
            int j=0;
            while(i+j+1<n && a[i+j] <= a[i+j+1]){
                j++;
            }
            i += j;
            count++;
        }
        else{
            int j=0;
            while(i+j+1<n && a[i+j] >= a[i+j+1]){
                j++;
            }
            i += j;
            count++;
        }
    }
    cout << count<<endl;
}
