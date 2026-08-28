class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& score) {
        //find top 3 people first
        priority_queue<pair<int,int>> pq;

        //pq will store the highest 3 numbers as well as their position in the array
        for(int i=0 ; i<score.size(); i++){
            pq.push({score[i],i});
        }
        //priority will be based on score;
        vector<string> answer(score.size());
        int rank = 1;
        int arrPos = pq.top().second;
        while(!pq.empty()){
            int arrPos = pq.top().second;          
            if(rank==1){
                answer[arrPos]="Gold Medal";
            }
            else if(rank ==2){
                answer[arrPos]="Silver Medal";
            }
            else if(rank ==3){
                answer[arrPos]="Bronze Medal";
            }
            else{
                answer[arrPos] = to_string(rank);
            }
            rank++;
            pq.pop();
        }
        return answer;
    }
};