#include<bits/stdc++.h>

int main()
{
    int h,w,n;
    std::cin>>h>>w>>n;
    std::queue<int> q;
    std::vector<std::vector<int>> ans(h,std::vector<int>(w));
    for(int i=0;i<n;i++){
        int tmp;
        std::cin>>tmp;
        for(int j=0;j<tmp;j++){
            q.push(i);
        }
    }

    for(int i=0;i<h;i++){
        if(i%2==0){
            for(int j=0;j<w;j++){
                ans[i][j] = q.front();
                q.pop();
            }
        }else{
            for(int j=w-1;j>=0;j--){
                ans[i][j] = q.front();
                q.pop();
            }
        }
    }
    for(int i=0;i<h;i++){
        for(int j=0;j<w;j++){
            if(j!=w-1)std::cout<<ans[i][j]+1<<" ";
            else std::cout<<ans[i][j]+1<<std::endl;
        }
    }
    return 0;
}