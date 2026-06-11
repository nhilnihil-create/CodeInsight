#include <iostream>

using namespace std;

int a[100010];

int main()
{
    int N; cin >> N;
    for (int i=0;i<N;++i) cin>>a[i], a[i]--;
    
    int ans=0;
    
    for(int i=0;i<N;++i) {
        if (a[i] == i) {
            int tmp=a[i];
            a[i]=a[i+1];
            a[i+1]=tmp;
            ans++;
        }
    }
    
    cout<<ans<<endl;
}