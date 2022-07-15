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
int preorderNum[1005], len_num = 0;


void preorderVisit(BTREE p)
{
    preorderNum[len_num] = p->val; 
    len_num++;
    if (p->left != NULL)
    {
        preorderVisit(p->left);
    }
    if (p->right != NULL)
    {
        preorderVisit(p->right);
    }

}
int* preorderTraversal(struct TreeNode* root, int* returnSize){
    len_num = 0;
    if (root != NULL)
    {
        preorderVisit(root);
    }
    *returnSize = len_num;
    return preorderNum;
}
