/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 * };
 */
//???????,???;
typedef struct TreeNode *BTREE, BTNode;

/***
BTREE tranverse(BTREE p)
{
    BTREE q = NULL;
    if (p->left == NULL)
    {
        return p;
    }
    if (p->left != NULL)
    {
        q = tranverse(p->left);
        q->right = p;
    }
    if (p->right != NULL)//??????????
    {
        q->left = p->right;
    }
    p->left = p->right = NULL;
    return p;

}
***/

struct TreeNode* upsideDownBinaryTree(struct TreeNode* root){
    BTREE p = NULL, q = NULL, r = NULL, s = NULL;
    while (root != NULL)
    {
        r = root->left;//??root??
        s = root->right;//??root??
        root->left = p;
        root->right = q;
        q = root;
        p = s;
        root = r;
    }
    return q;
}
