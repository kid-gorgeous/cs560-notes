//
//  main.cpp
//  heap
//
//  Created by Evan Julius on 2/27/23.
//

#include <iostream>
#include <vector>

using namespace std;

class Heap {
public:
    Heap(){}
    
    void insert(int data) {
        v.push_back(data);
        int index = v.size() - 1;
        while(index > 0 && v[parent(index)] > v[index]){
            swap(v[parent(index)], v[index]);
            index = parent(index);
        }
    }
    
    void decreaseKey(int i, int new_val) {
        v[i] = new_val;
        while(i != 0 && v[parent(i)] > v[i]){
            swap(v[parent(i)], v[i]);
            i = parent(i);
        }
    }
    
    int extractMinimum(){
        int min = v[0];
        int last = v.size() - 1;
        v[0] = v[last];
        v.pop_back();
        minHeapify(0);
        return min;
    }
    
    int extractMaximum(){
        int max = v[0];
        int last = v.size() - 1;
        v[0] = v[last];
        v.pop_back();
        maxHeapify(0);
        return max;
    }
    
    void maxHeapify(int i){
        int l = left(i);
        int r = right(i);
        int largest = i;
        if(l < v.size() && v[l] > v[i])
            largest = i;
        if(r < v.size() && v[r] > v[largest])
            largest = r;
        if(largest != i){
            swap(v[largest], v[i]);
            maxHeapify(largest);
        }
    }
    
    void minHeapify(int i){
        int l = left(i);
        int r = right(i);
        int smallest = i;
        if(l < v.size() && v[l] < v[i])
            smallest = l;
        if(r < v.size() && v[r] < v[smallest])
            smallest = r;
        if(smallest != i){
            swap(v[smallest], v[i]);
            minHeapify(smallest);
        }
    }
    
    int getMin() { return v[0]; }
    int getMax() { return v[0]; }
    
    void deleteKey(int i){
        decreaseKey(i, getMin() - 1);
        extractMinimum();
    }
    
    void print(){
        for(int i = 0; i < v.size(); i++){
            cout << v[i] << " ";
        }
        cout << endl;
    }
    
private:
    vector<int> v;
    int parent(int i){ return (i-1)/2; }
    int left(int i){ return (2*i+1); }
    int right(int i){ return (2*i+2); }
};


int main(int argc, const char * argv[]) {
    Heap h;
    h.insert(10);
    h.insert(20);
    h.insert(15);
    h.insert(12);
    h.insert(18);


    h.print();
    
    // TODO: add heapsort. Coming Wednesday;
}
