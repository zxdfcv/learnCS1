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
int postordernum[1005], len_num = 0;

void postorderVisit(BTREE p)
{
    if (p->left != NULL)
    {
        postorderVisit(p->left);
    }
    if (p->right != NULL)
    {
        postorderVisit(p->right);
    }
    postordernum[len_num] = p->val;
    len_num++;
}
int* postorderTraversal(struct TreeNode* root, int* returnSize){
    len_num = 0;
    if (root != NULL)
    {
        postorderVisit(root);
    }
    *returnSize = len_num;
    return postordernum;
}
