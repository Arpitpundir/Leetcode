// Mistakes
// 1. I need to get better at dry run code with examples before running it
// 2. Should analyze comparison condition more carefully
class Solution {
public:
    string smallestSubsequence(string s, int k, char letter, int repetition) {
        int n = s.size();
        stack<char> st;
        int q = 0, rem = 0;
        for(int i=0;i<n;i++){
            if(s[i]==letter) rem++;
        }
        for(int i=0;i<n;i++){
            int temp = rem+q-1;
            while(!st.empty() && st.top() > s[i] && st.size()+n-i > k && (st.top() == letter?(rem+q-1)>=repetition:true)){
                char curr = st.top();
                st.pop();
                if(curr == letter) q--;
            }
            
            if(st.size() < k){
                            int l = k-st.size(), r = repetition-q;


                if(s[i]==letter){
                    st.push(s[i]);
                    q++;
                }else if(l > r){

                    st.push(s[i]);
                }
            }
            if(s[i]==letter) rem--;
        }
        string ans;
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(), ans.end());
        return ans;
    }
};