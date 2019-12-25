#include <bits/stdc++.h>



using namespace std;

void heapify_down(vector<int> &arr, int i) {
    int n = arr.size();
    int left = i * 2 + 1;
    int right = i * 2 + 2;
    int max_index = i;
    if(left < n && arr[left] > arr[max_index]) {
        max_index = left;
    }
    if(right < n && arr[right] > arr[max_index]) {
        max_index = right;
    }
    if(i != max_index) {
        swap(arr[i], arr[max_index]);
        heapify_down(arr, max_index);
    }
}

void heapify_up(vector<int> &arr, int i) {
    int parent = (i+1)/2 - 1;
    if(parent < 0) {
        return;
    }
    int max_index = i;
    if(arr[parent] < arr[i]) {
        swap(arr[parent], arr[i]);
        heapify_up(arr, parent);
    }
}
void delete_max(vector<int> &arr) {
    int n = arr.size();
    if(n == 0) {
        return;
    }
    swap(arr[0], arr[n-1]);
    arr.pop_back();
    heapify_down(arr, 0);
}
void insert(vector<int> &arr, int ele) {
    arr.push_back(ele);
    int n = arr.size();
    heapify_up(arr, n-1);
}
void build_heap(vector<int> &arr) {
    int n = arr.size();
    for(int i = n/2 - 1; i>= 0; i--) {
        heapify_down(arr, i);
    }
}

int main() {
    int n;
    cin >> n;
    vector <int> arr(n);
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    build_heap(arr);
    for(int i = 0; i < n; i++) {
        cout << arr[0] << endl;
        delete_max(arr);
    }
    return 0;
}
