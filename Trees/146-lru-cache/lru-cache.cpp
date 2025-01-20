class LRUCache {
    queue <int> dq;
    unordered_map<int,int> mp, cnt; 
    int size = 0;
public:
    LRUCache(int capacity) {
        this->size = capacity;
    }
    
    int get(int key) {
        if(cnt.find(key) == cnt.end()) return -1;
        dq.push(key);
        cnt[key]++;
        return mp[key];
    }
    
    void put(int key, int value) {
        
        mp[key] = value;
        cnt[key]++;
        dq.push(key);
        while(cnt.size() > size){
            int curKey = dq.front();
            dq.pop();
            if(cnt[curKey]-- == 1) cnt.erase(curKey);
        }
        return ; 
    }
};

/**
 * Your LRUCache object will be indqantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */