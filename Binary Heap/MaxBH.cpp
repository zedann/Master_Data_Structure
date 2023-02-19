#include<vector>
#include<iostream>
#include<cassert>
using namespace std;
class MaxHeap 
{
    int *array { };
    int size { };
    int capacity {1000};
    
    int left_child(int node)
    {
        int pos = 2 * node + 1;
        return (pos >= size) ? -1 :  pos;
    }
    int right_child(int node)
    {
        int pos = 2 * node + 2;
        return (pos >= size) ? -1 :  pos;
    }
    int parent(int node)
    {
        
        return node == 0 ? -1 : (node - 1)/2;
    }
    void heapify_up(int child_pos)
    {
        // stop when parent is larger (or no parent)
        int par_pos = parent(child_pos);
        if(child_pos == 0 || array[par_pos] >= array[child_pos])
            return;
        swap(array[par_pos],array[child_pos]);
        heapify_up(par_pos);
    }
    void heapify_down(int parent_pos)
    {
        int child_pos = left_child(parent_pos);
        int right_pos = right_child(parent_pos);
        if(child_pos == -1)
            return;
        if(right_pos != -1 && array[right_pos] > array[child_pos])
            child_pos = right_pos;
        
        if(array[child_pos] > array[parent_pos])
        {
            swap(array[right_pos],array[parent_pos]);
            heapify_down(child_pos);
        }
        
    }
    void heapify()
    {
        for(int i = size / 2 - 1 ; i >= 0 ;i++)
            heapify_down(i);
    }
    public:
    MaxHeap()
    {
        array = new int[capacity] { };
        size = 0;
    }
    MaxHeap(vector<int>&v)
    {
        assert((int)v.size() <= capacity);
        array = new int[capacity] { };
        size = v.size();
        for(int i = 0 ;i <(int)v.size() ;i++)
            array[i] = v[i];
        heapify();
    }
    ~MaxHeap()
    {
        delete[]array;
        array =nullptr;
    }

    void push(int val)
    {
        assert(size + 1 <= capacity);
        array[size++] = val;
        heapify_up(size - 1);
    }
    void pop()
    {
        assert(!empty());
        array[0] = array[--size];
        heapify_down(0);
    }
    int top(){
        assert(!empty());
        return array[0];
    }
    bool empty()
    {
        return size == 0;
    }
};
void create_heap_nlogn()
{
    MaxHeap heap;
    vector<int> v { 2, 17, 22, 10, 8, 37,14, 19, 7, 6, 5, 12, 25, 30 };
    for(int i = 0 ;i < v.size() ;i++)
        heap.push(v[i]);
    while (!heap.empty())
    {
        cout << heap.top() << " ";
        heap.pop();
    }
}
void create_heap_n()
{
    vector<int> v { 2, 17, 22, 10, 8, 37,14, 19, 7, 6, 5, 12, 25, 30 };
    MaxHeap heap(v);
    while (!heap.empty()) {
		cout << heap.top() << " ";
		heap.pop();
	}
}
int main()
{
    create_heap_n();
    return 0;
}