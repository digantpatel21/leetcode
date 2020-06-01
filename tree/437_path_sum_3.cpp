/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {

/**
             5
            / \
           4   8
          /   / \
         11  13  4
        / \     / \
       7   2   5   1
       
       Hash logic is added by observing this failure scenario
       without hash we can get only 2 paths
       1. 5-4-11-2
       2. 5-8-4-5
       
       in this case we are missing one path that is 4-11-7, why we are missing ?? good question
       because that starts with 4 that is left node of 5, and we are using recursion in which it 
       adds all values from root of tree that is 5. 
       
       code with out hash:
        
        int dfsr(TreeNode * root, int prefixSum, int targetSum, map<int, int> &hash)
        {
            if(!root)
                return 0;
            int curSum = prefixSum + root->val;
            int curCnt = 0;
            if(curSum == targetSum)
                curCnt++;

            int leftSum = dfsr(root->left, curSum, targetSum, hash);
            int rightSum =dfsr(root->right, curSum, targetSum, hash);

            return curCnt+leftSum + rightSum;
        }
        int pathSum(TreeNode* root, int sum) {
            map<int,int> hash;

            return dfsr(root, 0, sum, hash);

        }

        which looks simple !!!
        
        why hash i have concluded :P
        i have thought something like whenever we are at some curSum we are increment that count in hash
       
*/
public:
    int dfsr(TreeNode * root, int prefixSum, int targetSum, map<int, int> &hash)
    {
        if(!root)
            return 0;
        int curSum = prefixSum + root->val;
        int curCnt = hash.count(curSum - targetSum)?hash[curSum-targetSum]:0;
        if(curSum == targetSum)
            curCnt++;
        
        hash[curSum]++;
        
        int leftSum = dfsr(root->left, curSum, targetSum, hash);
        int rightSum =dfsr(root->right, curSum, targetSum, hash);
        hash[curSum]--;
        return curCnt+leftSum + rightSum;
    }
  
    int pathSum(TreeNode* root, int sum) {
        map<int,int> hash;
        
        return dfsr(root, 0, sum, hash);
        
    }
};

void trimLeftTrailingSpaces(string &input) {
    input.erase(input.begin(), find_if(input.begin(), input.end(), [](int ch) {
        return !isspace(ch);
    }));
}

void trimRightTrailingSpaces(string &input) {
    input.erase(find_if(input.rbegin(), input.rend(), [](int ch) {
        return !isspace(ch);
    }).base(), input.end());
}

TreeNode* stringToTreeNode(string input) {
    trimLeftTrailingSpaces(input);
    trimRightTrailingSpaces(input);
    input = input.substr(1, input.length() - 2);
    if (!input.size()) {
        return nullptr;
    }

    string item;
    stringstream ss;
    ss.str(input);

    getline(ss, item, ',');
    TreeNode* root = new TreeNode(stoi(item));
    queue<TreeNode*> nodeQueue;
    nodeQueue.push(root);

    while (true) {
        TreeNode* node = nodeQueue.front();
        nodeQueue.pop();

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int leftNumber = stoi(item);
            node->left = new TreeNode(leftNumber);
            nodeQueue.push(node->left);
        }

        if (!getline(ss, item, ',')) {
            break;
        }

        trimLeftTrailingSpaces(item);
        if (item != "null") {
            int rightNumber = stoi(item);
            node->right = new TreeNode(rightNumber);
            nodeQueue.push(node->right);
        }
    }
    return root;
}

int stringToInteger(string input) {
    return stoi(input);
}

int main() {
    string line;
    while (getline(cin, line)) {
        TreeNode* root = stringToTreeNode(line);
        getline(cin, line);
        int sum = stringToInteger(line);
        
        int ret = Solution().pathSum(root, sum);

        string out = to_string(ret);
        cout << out << endl;
    }
    return 0;
}