/*Given an array nums and a target value k, find the maximum length of a subarray that sums to k. If there isn't one, return 0 instead.

Note:
The sum of the entire nums array is guaranteed to fit within the 32-bit signed integer range.

Example 1:
Given nums = [1, -1, 5, -2, 3], k = 3,
return 4. (because the subarray [1, -1, 5, -2] sums to 3 and is the longest)

Example 2:
Given nums = [-2, -1, 2, 1], k = 1,
return 2. (because the subarray [-1, 2] sums to 1 and is the longest)

Follow Up:
Can you do it in O(n) time?
*/

class Solution {
public:
    int maxSubArrayLen(vector<int>& nums, int k) {
        int n = nums.size();
        map<int, int> m;
        int res = 0;
        int i=0;
        int start = 0;
        int runSum = 0;
        
        for( int i=0; i<n; i++ ) {
            runSum += nums[i];
            if( runSum == k ) {
                res = max(res, i+1);
            } else if( m.find(runSum-k) != m.end() ) {
                res = max(res, i-m[runSum-k] );
            }
            if(m.find(runSum) == m.end() ){
                m[runSum] = i;
            }
        }
        
        
        return res;
    }   
};