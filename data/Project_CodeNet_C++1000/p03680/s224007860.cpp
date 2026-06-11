#include <iostream>
using namespace std;
int n;
int a[100010];
main() {
    cin>>n;
    for(int i=0;i<n;++i)cin>>a[i+1];
    int ans=0,p=0;
    for(p=1;ans<n&&p!=2;p=a[p],++ans);
    cout<<(p!=2?-1:ans)<<endl;
}