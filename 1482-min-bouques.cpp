class Solution {
public:
    bool check(int d, vector<int> b, int m, int k){
        int n = b.size();
        long int currM = 0, count  = 0;
        
        for(int i = 0;i<n;i++){
            if(b[i]<=d){
                count++;
            }else{
                count = 0;
            }
            if(count == k){
                currM++;
                count = 0;
            }
        }
        
        if(currM >= m) return true;
        return false;
    }
    int minDays(vector<int>& b, int m, int k) {
        auto p = minmax_element(b.begin(), b.end());
        long int st = *p.first, end = *p.second;
        long int reqFlowers = (long)m*k;
        if(reqFlowers > b.size()) return -1;
        while(st<end){
            long int mid = st+floor((end-st)/2);
            if(check(mid, b, m, k)){
                end = mid;
            }else{
                st = mid+1;
            }
        }
        return st;
    }
};