#include <bits/stdc++.h>

using namespace std;
typedef pair<int,int> pii;

int n;
int arr[100100];
vector<int> vec;
void print(int t) {
    puts(t==1?"First":"Second");
    exit(0);
}

int getv(int x) {
    int i, f = 0, p = -arr[1];
    for (i=1;i<=n;i++) {
        if (i==n||arr[i]!=arr[i+1]) {
            if (p<=x&&x<=i-arr[i+1]) {
                f |= abs((i-arr[i]-x)%2);
            }
            p = i-arr[i+1];
        }
    }
    return f;
}

int main() {
    int i;

    scanf("%d",&n);
    for (i=1;i<=n;i++) scanf("%d",&arr[i]);
    sort(arr+1,arr+n+1,greater<int>());
    print(getv(0)&&(getv(-2)||getv(2)));

    return 0;
}
