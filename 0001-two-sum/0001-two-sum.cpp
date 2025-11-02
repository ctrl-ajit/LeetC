class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> map; // Store value and its index
        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i]; // What value we need
            if (map.count(complement)) {
                // Found the other part of the pair
                return {map[complement], i};
            }
            map[nums[i]] = i; // Store this number's index
        }
        return {}; // No solution found
    }
};
   
