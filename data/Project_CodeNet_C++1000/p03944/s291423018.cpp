#include <bits/stdc++.h>
using namespace std;

int main() {
    int W, H, N;
    vector<int> x, y, a;
    cin >> W >> H >> N;
    int width = W;
    int height = H;
    int maxW_l=0, maxW_u=0;
    int maxH_l=0, maxH_u=0;

    for(int i=0; i<N; i++){
        int s1,s2,s3;
        cin >> s1 >> s2 >> s3;
        x.push_back(s1);
        y.push_back(s2);
        a.push_back(s3);
        if(a[i]==1)
        {
            if(maxW_l < x[i]) maxW_l = x[i];
        }else if(a[i]==2)
        {
            if(maxW_u < width-x[i]) maxW_u = width-x[i];
        }else if(a[i]==3)
        {
            if(maxH_l < y[i]) maxH_l = y[i];
        }else
        {
            if(maxH_u < height-y[i]) maxH_u = height-y[i];          
        }
    }
    if((width <= maxW_l + maxW_u) || (height <= maxH_l + maxH_u))
    {
        cout << "0" << endl;
    }else
    {
        cout << (width - (maxW_l+maxW_u)) * (height - (maxH_l + maxH_u)) << endl;
    }
    return 0;
}