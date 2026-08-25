class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        //one number which is the kth largest one
        //lets make a min heap
        priority_queue<int,vector<int>,greater<int>> pq;
        for(int x:nums){
            pq.push(x);
        }
        while(pq.size()>k){
            pq.pop();
        }

        int ans = pq.top();
        return ans;
    }
};