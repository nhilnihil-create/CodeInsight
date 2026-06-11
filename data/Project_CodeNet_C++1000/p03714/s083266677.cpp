#include <iostream>
#include <vector>

using namespace std;

//一次元vector用
void swap(vector<long long> &heap, int i, int j){
    long long tmp = heap[i];
    heap[i]=heap[j];
    heap[j]=tmp;
}

void minHeapify(vector<long long> &heap, int n){
    int l,r,smallest,last;
    l=2*n+1;
    r=2*n+2;
    smallest=n;
    last=heap.size();

    if (l<last && heap[l] < heap[smallest])smallest=l;
    if (r<last && heap[r] < heap[smallest])smallest=r;
    if(smallest!=n){
        swap(heap,n,smallest);
        minHeapify(heap,smallest);
    }
}

long long minHeapPop(vector<long long> &heap){
    long long min_=heap[0];
    heap[0]=heap[heap.size()-1];
    heap.pop_back();
    minHeapify(heap,0);

    return min_;
}

void minHeapPush(vector<long long> &heap, long long num){
    heap.push_back(num);
    int i = heap.size()-1;
    int parent = (i-1)/2;
    while (i>0 && heap[parent] > heap[i]){
        swap(heap,i,parent);
        i=parent;
        parent=(i-1)/2;
    }
}

void buildMinHeap(vector<long long> &heap){
    int size=heap.size();
    for(int i=(size-1)/2; i>=0; i--){
        minHeapify(heap,i);
    }
}

//-----------------maxHeap--------------------------
void maxHeapify(vector<long long> &heap, int n){
    int l,r,largest,last;
    l=2*n+1;
    r=2*n+2;
    largest=n;
    last=heap.size();

    if (l<last && heap[l] > heap[largest])largest=l;
    if (r<last && heap[r] > heap[largest])largest=r;
    if(largest!=n){
        swap(heap,n,largest);
        maxHeapify(heap,largest);
    }
}

long long maxHeapPop(vector<long long> &heap){
    long long max_=heap[0];
    heap[0]=heap[heap.size()-1];
    heap.pop_back();
    maxHeapify(heap,0);

    return max_;
}

void maxHeapPush(vector<long long> &heap, long long num){
    heap.push_back(num);
    int i = heap.size()-1;
    int parent = (i-1)/2;
    while (i>0 && heap[parent] < heap[i]){
        swap(heap,i,parent);
        i=parent;
        parent=(i-1)/2;
    }
}

void buildMaxHeap(vector<long long> &heap){
    int size=heap.size();
    for(int i=(size-1)/2; i>=0; i--){
        maxHeapify(heap,i);
    }
}

int main(){
    int N;
    cin >> N;
    vector<vector<long long>> a(3,vector<long long>(N,0));
    vector<long long> first(N+1,0);
    vector<long long> second(N+1,0);

    for (int i=0; i<3; i++){
        for(int j=0; j<N; j++){
            cin >> a[i][j];
            if (i==0){
                first[0]+=a[0][j];
            }else if(i==2){
                second[0]+=a[2][j];
            }
        }
    }
    buildMinHeap(a[0]);
    buildMaxHeap(a[2]);

    for(int i=1; i<N+1; i++){
        minHeapPush(a[0],a[1][i-1]);
        maxHeapPush(a[2],a[1][N-i]);
        first[i]+=first[i-1]+a[1][i-1]-minHeapPop(a[0]);
        second[i]+=second[i-1]+a[1][N-i]-maxHeapPop(a[2]);
    }
    long long ans=-100000000000000000;
    for(int i=0; i<N+1; i++){
        long long tmp = first[i]-second[N-i];
        if (tmp>ans){
            ans=tmp;
        }
    }
    cout<<ans<<'\n';
}