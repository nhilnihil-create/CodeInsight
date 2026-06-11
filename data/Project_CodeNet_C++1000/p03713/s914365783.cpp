#include<iostream>
#include<cmath>
using namespace std;
int min_one_way(int h, int w){
    return min(h,w);
}
int min_two_way(int h, int w){
    int divh = h/3;
    int divw = w/2;
    int s1 = divh*w;
    int s2 = (h-divh)*divw;
    int s3 = (h-divh)*(w-divw);
    int min_horizon1 = min(min(s1,s2),s3);
    int max_horizon1 = max(max(s1,s2),s3);
    divh++;
    s1 = divh*w;
    s2 = (h-divh)*divw;
    s3 = (h-divh)*(w-divw);
    int min_horizon2 = min(min(s1,s2),s3);
    int max_horizon2 = max(max(s1,s2),s3);
    divw = w/3;
    divh = h/2;
    s1 = divw*h;
    s2 = (w-divw)*divh;
    s3 = (w-divw)*(h-divh);
    int min_vertical1 = min(min(s1,s2),s3);
    int max_vertical1 = max(max(s1,s2),s3);
    divw++;
    s1 = divw*h;
    s2 = (w-divw)*divh;
    s3 = (w-divw)*(h-divh);
    int min_vertical2 = min(min(s1,s2),s3);
    int max_vertical2 = max(max(s1,s2),s3);
    return min(min(max_horizon1-min_horizon1,max_horizon2-min_horizon2),min(max_vertical1-min_vertical1,max_vertical2-min_vertical2));
}
int main(void){
    int h,w;
    cin>>h>>w;
    if(h%3==0 || w%3==0){
        cout<<0<<endl;
    }
    else{
        cout<<min(min_one_way(h,w),min_two_way(h,w))<<endl;
    }
    return 0;
}