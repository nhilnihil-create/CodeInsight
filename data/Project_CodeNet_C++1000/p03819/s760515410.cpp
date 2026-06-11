#include<cstdio>
#include<vector>
#include<algorithm>
#include<functional>
class Fenwick{
private:
    int length, vecsize;
    long long *vec;
public:
    Fenwick(int l);
    ~Fenwick();
    void add(int a,long long x);
    long long sum(int a);
    long long operator[](int i);
    void init();
    void set(int a,long long x);
};
Fenwick::Fenwick(int l){
    this->length=l;
    vecsize=1;
    while(l>0){
        vecsize<<=1;
        l>>=1;
    }
    vecsize++;
    this->vec=new long long[vecsize];
    init();
}
Fenwick::~Fenwick(){
    delete[] vec;
}
// v[0]+v[1]+...+v[a-1]
long long Fenwick::sum(int a){
    if(a<0)return 0;
    if(a>length)a=length;
    long long sum=0;
    while(a>0){
        sum+=vec[a];
        a-=a&(-a);
    }
    return sum;
}
// v[a]+=x
void Fenwick::add(int a,long long x){
    while(a<length){
        vec[a]+=x;
        a+=a&(-a);
    }
}
void Fenwick::init(){
    for(int i=0;i<vecsize;i++){
        vec[i]=0;
    }
}
int main(){
    int n,m,l,r;
    scanf("%d%d",&n,&m);
    std::vector<std::pair<int,int>> vp;
    for(int i=0;i<n;i++){
        scanf("%d%d",&l,&r);
        vp.push_back({r-l+1,l});
    }
    std::sort(vp.begin(),vp.end(),std::greater<std::pair<int,int>>());
    Fenwick cumsum(m+2);
    for(int d=1;d<=m;d++){
        while(!vp.empty() && (*vp.rbegin()).first<=d){
            l=(*vp.rbegin()).second;
            r=(*vp.rbegin()).first+l-1;
            cumsum.add(l,1);
            cumsum.add(r+1,-1);
            vp.pop_back();
        }
        int ans=vp.size();
        for(int k=d;k<=m;k+=d){
            ans+=cumsum.sum(k);
        }
        printf("%d\n",ans);
    }
    return 0;
}