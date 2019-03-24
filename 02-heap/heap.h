#ifndef HEAP_H
#define HEAP_H
template<typename Item>
class MaxHeap{
private:
    Item * data;
    int count;
    int capacity;
    void shiftUp(int k){
        // 边界
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
#endif // HEAP_H
