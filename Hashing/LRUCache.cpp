/**
Design and implement a data structure for LRU (Least Recently Used) cache.
It should support the following operations: get and set.

    get(key) - Get the value (will always be positive) of the key if the key exists in the cache, otherwise return -1.
    set(key, value) - Set or insert the value if the key is not already present. When the cache reaches its capacity,
    it should invalidate the least recently used item before inserting the new item.

The LRU Cache will be initialized with an integer corresponding to its capacity.
Capacity indicates the maximum number of unique keys it can hold at a time.

Definition of “least recently used” : An access to an item is defined as a get or a set operation of the item.
“Least recently used” item is the one with the oldest access time.
Input : 
         capacity = 2
         set(1, 10)
         set(5, 12)
         get(5)        returns 12
         get(1)        returns 10
         get(10)       returns -1
         set(6, 14)    this pushes out key = 5 as LRU is full. 
         get(5)        returns -1 
         
*/
class Node{
    public:
        int key;
        int value;
        Node * next;
        Node * prev;
        Node(int x, int y){
            this->key = x;
            this->value = y;
            this->next = NULL;
            this->prev = NULL;
        }
};

unordered_map<int, Node *> mp;
Node *lruPtr, *mruPtr;
int maxCacheSize;
Node *tempPtr;
LRUCache::LRUCache(int capacity) {
    maxCacheSize = capacity;
    mp.clear();
    lruPtr = NULL;
    mruPtr = NULL;
}
void updateList(){
    if(tempPtr->next){
            tempPtr->next->prev = tempPtr->prev;
            if(tempPtr->prev){
                tempPtr->prev->next = tempPtr->next;
            }else{
                lruPtr = lruPtr->next;
            }
            tempPtr->prev = mruPtr;
            mruPtr->next = tempPtr;
            tempPtr->next = NULL;
            mruPtr = mruPtr->next;
        }
}
int LRUCache::get(int key) {
    if(mp.find(key) == mp.end()){
        return -1;
    }else{
        tempPtr = mp[key];
        updateList();
        return tempPtr->value;
    }
}

void LRUCache::set(int key, int value) {
    if(maxCacheSize == 0){
        return;
    }
    if(mp.find(key) != mp.end()){
        tempPtr = mp[key];
        updateList();
        tempPtr->value = value;
    }else{
        if(lruPtr == NULL){
            lruPtr = new Node(key,value);
            mruPtr = lruPtr;
            mp[key] = lruPtr;
        }else{
            if(mp.size() == maxCacheSize){
                tempPtr = lruPtr;
                mp.erase(tempPtr->key);
                lruPtr = lruPtr->next;
                if(lruPtr){
                    lruPtr->prev = NULL;
                }else{
                    mruPtr = NULL;
                }
                tempPtr->next = NULL;
                delete(tempPtr);
                tempPtr = NULL;
                set(key,value);
            }else{
                tempPtr = new Node(key,value);
                mp[key] = tempPtr;
                mruPtr->next = tempPtr;
                tempPtr->prev = mruPtr;
                mruPtr = mruPtr->next;
            }
        }
    }
}
