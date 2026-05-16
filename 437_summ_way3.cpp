class Solution {
    public:
        int pathSum(TreeNode* root, int targetSum) {
            unordered_map<long, int> prefixSum;
            prefixSum[0] = 1;
            return dfs(root, 0, targetSum, prefixSum);
        }
    
    private:
        int dfs(TreeNode* node, long currentSum, int targetSum, unordered_map<long, int>& prefixSum) {
            if (!node) return 0;
    
            currentSum += node->val;
            int count = prefixSum[currentSum - targetSum];
    
            prefixSum[currentSum]++;
            count += dfs(node->left, currentSum, targetSum, prefixSum);
            count += dfs(node->right, currentSum, targetSum, prefixSum);
            prefixSum[currentSum]--;
    
            return count;
        }
    };
