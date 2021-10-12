class Solution {
public:
    long long gridGame(vector<vector<int>>& grid) {
        long long firstRowSum = 0, secondRowSum = 0,
        n = grid[0].size();
        
        for(int i=0;i<n;i++){
            firstRowSum+=grid[0][i];
            secondRowSum+=grid[1][i];
        }
        
        long long int p1r1 = 0, p1r2 = secondRowSum, res1 = 0, res2 = LLONG_MAX;
        
        for(int i=0;i<n;i++){
            p1r1 += grid[0][i];
            if(i!=0) p1r2 -= grid[1][i-1];
            res2 = min(res2,max(firstRowSum-p1r1, secondRowSum-p1r2));
        }
        return res2;
    }
};