class Solution {
public:
    int check(vector<int> w, int c){
        int d = 0;
        int n = w.size(), currC = 0;
        for(int i=0;i<n;i++){
            if(currC+w[i]>c){
                d++;
                currC = 0;
            }
            currC+=w[i];
        }
        if(currC!=0) d+=1;
        return d;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        long int n = weights.size();
        long int end = accumulate(weights.begin(), weights.end(), 0L);
        long int st = *max_element(weights.begin(), weights.end());        
        while(st<end){
            long int mid = st+floor((end-st)/2);
            int d = check(weights,mid);
            //cout<<d<<endl;
            if(d > days){
                st = mid+1;
            }else{
                end = mid;
            }
        }
        return st;
    }
};