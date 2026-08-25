class Solution {
public:
    string frequencySort(string s) {
        unordered_map<char,int> freq;
        for(char x : s){
            freq[x]++;
        }
        priority_queue<pair<int,char>> pq;
        //now we want to push the frequency along with char in the pq
        for(auto&[ch,count]:freq){
            pq.push({count,ch});
        }
        //its a max heap, so pq.top() gives max frequency
        std::string sq;
        while(!pq.empty()){
            int count = pq.top().first;
            char cr = pq.top().second;
            for(int i=0; i<count;i++){
                sq.push_back(cr);
            }
            pq.pop();
        }
        return sq;
    }
};