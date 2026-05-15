class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {
        int s = nums.size();
        vector<int> res(s, -1);
        stack<int> st;
        for (int i = 0 ; i < 2*s; ++i) {
            int index = i % s;
            while (!st.empty() && nums[index] > nums[st.top()]) {
                res[st.top()] = nums[index];
                st.pop();
            }
            if (i < s) st.push(index);
        }
        return res;
    }
};

