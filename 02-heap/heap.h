#ifndef HEAP_H
#define HEAP_H
template<typename Item>
class MaxHeap{
private:
    Item * data;
    int count;
    int capacity;
    void shiftUp(int k){
        // child is valid, so k > 1
        // child value is more than parent value data[k] > data[k/2]
        // swap child value and parent value
        // cosider continued parent update k = k / 2
        while(k>1 && data[k/2] < data[k]){
            swap(data[k/2], data[k]);
            k /= 2; // 更新到父节点，
            // k>1 until root
        }
    }
    void shiftDown(int k){
        while(2*k <= count){
            // compare between left with right node
            // left node
            int j = 2*k;// left child node
            // right node
            if(j + 1 <= count && data[j+1] > data[j])
                j += 1;
            if(data[k] > data[j]){
                break;
            }
            // swap parent node with child node
            swap(data[k], data[j]);
            // update k
            k = j;
        }
    }
public:
    MaxHeap(int capacity):count(0){
        // index form 1
        this->capacity = capacity;
        data = new Item[capacity + 1];
    }
    MaxHeap(Item arr[], int n){
        data = new Item[n+1];
        this->capacity = n;
        for(int i = 0; i < n; i++){
            data[i+1] = arr[i];
        }
        count = n;
        // heapify O(n)
        // the first non leaf node n/2
        for(int i = count/2; i >=1; i--){
            shiftDown(i);
        }
    }
    ~MaxHeap(){
        delete[] data;
    }
    int size(){
        return count;
    }
    bool isEmpty(){
        return count == 0;swap(data[1], data[count]);
    }
    void insert(Item item){
        //index form 1;
        assert(count + 1 <= capacity);
        data[count+1] = item;
        count++;
        shiftUp(count);
    }
    Item pop(){
        assert(count > 0);
        Item ret = data[1];
        swap(data[1], data[count]);
        count--;
        shiftDown(1);
        return ret;
    }
};
// heap sort
// method 1:  insertion builds heap
template<typename T>
void heapSort1(T arr[], int n){
    MaxHeap<T> maxheap = MaxHeap<T>(n);
    for(int i = 0; i < n; i++){
        maxheap.insert(arr[i]);
    }
    for(int i = n-1; i >=0; i--){
        arr[i] = maxheap.pop();
    }
}
// method 2: build heap through heapifying
template<typename T>
void heapsort2(T arr[], int n){
    MaxHeap<T> maxheap = MaxHeap<T>(arr, n);
    for(int i = n-1; i >= 0; i--){
        arr[i] = maxheap.pop();
    }
}
// no more space
// sorted in place
// method 3: space O(1)
template<typename T>
void _shiftDown(T arr[], int n, int k){
    // left child is valid
    // arr[0,n)
    while(2*k + 1 < n){
        // left child max
        int  j = 2*k + 1;
        // right child is valid && max
        if (2*k + 2 < n && arr[j] < arr[j+1]){
            j = 2*k + 2;
        }
        // child is more less than parent
        if(arr[j] < arr[k]){
            break;
            // do nothing, it is actually heap
        }
        swap(arr[j], arr[k]);
        // update k
        k = j;
    }
}
template<typename T>
void _heapify(T arr[], int n){
    // i==0 root
    for(int i = (n-1)/2; i >= 0; i--){
        //[0,n)
        _shiftDown(arr, n, i);
    }
}
template<typename T>
void heapsort(T arr[], int n){
    // left 2i -> 2i + 1
    // right 2i+1 -> 2i+2
    // parent i/2 ->(i-1)/2
    // non-leaf
    // (count-1)/2
    _heapify(arr, n);
    // last one element in array; no operator
    for(int i = n-1; i > 0; i--){
        swap(arr[i], arr[0]);
        _shiftDown(arr, i, 0);
    }
}
#endif // HEAP_H
