/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */

typedef struct TreeNode *BTREE, BTNode; 
int inorderNum[1005], len_num = 0;

void inorderVisit(BTREE p)
{
    if (p->left != NULL)
    {
        inorderVisit(p->left);
    }
        inorderNum[len_num] = p->val; 
    len_num++;
    if (p->right != NULL)
    {
        inorderVisit(p->right);
    }
}

int* inorderTraversal(struct TreeNode* root, int* returnSize){
    len_num = 0;
    if (root != NULL)
    {
        inorderVisit(root);
    }
    *returnSize = len_num;
    return inorderNum;
}
