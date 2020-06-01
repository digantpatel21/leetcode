/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
    
    string arr1,arr2;
    
    TreeNode* fetchNode(TreeNode *root, int data) {
        
        if(root == NULL)
            return NULL;
        
        if(root->val == data)
            return root;
        
        TreeNode* left = fetchNode(root->left, data);
        
        if(left != NULL)
            return left;

        TreeNode* right = fetchNode(root->right, data);
        
        if(right != NULL)
            return right;
        
        return NULL;
    }
    
    bool checkIfTreesAreIdenticalOrNot(TreeNode* s, TreeNode* t) {
        
        if(s == NULL && t == NULL)
            return true;
        
        if((s != NULL && t == NULL) ||(s == NULL && t != NULL)) {
            return false;
        }
        
        if(s->val != t->val) {
            return false;
        }
        
        return checkIfTreesAreIdenticalOrNot(s->left, t->left) && checkIfTreesAreIdenticalOrNot(s->right, t->right);
    }
    
public:
    bool isSubtree(TreeNode* s, TreeNode* t) {
        
        TreeNode* superTreeRoot = fetchNode(s, t->val);
        
        if(superTreeRoot == NULL)
            return false;
        
        cout<<"check-1 : "<<superTreeRoot->val<<endl;
        return checkIfTreesAreIdenticalOrNot(superTreeRoot,t);    
        
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

string boolToString(bool input) {
    return input ? "True" : "False";
}

int main() {
    string line;
    while (getline(cin, line)) {
        TreeNode* s = stringToTreeNode(line);
        getline(cin, line);
        TreeNode* t = stringToTreeNode(line);
        
        bool ret = Solution().isSubtree(s, t);

        string out = boolToString(ret);
        cout << out << endl;
    }
    return 0;
}