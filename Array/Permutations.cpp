class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
      vector<vector<int>> ans;

        // Step 1: sort the input
        sort(nums.begin(), nums.end());

        // Step 2: push the first permutation
        ans.push_back(nums);

        // Step 3: use while loop to generate the next permutations
        while (next_permutation(nums.begin(), nums.end())) {
            ans.push_back(nums);
        }

        return ans;
    }
};