<!--
 * @Description: 1. 确定递归函数的参数和返回值：
-->
二叉树：
1.度：一个结点的度为[0,1,2],即这个树有0，1，2个叶子
2.深度：一个二叉树的深度就是从根节点到叶子结点的长度，根节点记为1；
3.对于满二叉树：如果⼀棵⼆叉树只有度为0的结点和度为2的结点，并且度为0的结点在同⼀层上，则这棵⼆叉树为满⼆叉树。
也可以说这深度为k则，有k^2-1个结点。
4.完全二叉树：
在完全⼆叉树中，除了最底层节点可能没填满外，其余每层节点数都达到最⼤值，
并且最下⾯⼀层的节点都集中在该层最左边的若⼲位置。若最底层为第 h层，
则该层包含 1~ 2^h -1 个节点。
5.二叉搜索树：
若它的左⼦树不空，则左⼦树上所有结点的值均⼩于它的根结点的值；
若它的右⼦树不空，则右⼦树上所有结点的值均⼤于它的根结点的值；
它的左、右⼦树也分别为⼆叉排序树
6.平衡二叉搜索树：
又被称为AVL（Adelson-Velsky and Landis）树，且具有以下性质：
它是⼀棵空树或它的左右两个⼦树的⾼度差的绝对值不超过1，并且左右两个⼦树都是⼀棵平衡⼆叉树。
7.二叉树的存储方式：
    ~链式存储，使用指针
    ~顺序存储，使用数组
        a   b   c   d   e   f   g
        0   1   2   3   4   5   6
        如果父节点的数组下标是i，那么他左孩子的数组下标就是i*2+1，右孩子就是i*2+2;
8.二叉树的遍历方式：
    ~深度优先遍历：先往深处走，遇见叶子结点再往回走。
        ·前序遍历（递归法，迭代法）先遍历根节点，再遍历左右结点（第一个遍历根结点）
        ·中序遍历（递归法，迭代法）先遍历左结点，再遍历根节点，最后遍历右结点（第二个遍历根节点）
        ·后序遍历（递归法，迭代法）先遍历左右结点，最后遍历根结点（第三个遍历根节点）
    ~广度优先遍历：一层一层的去遍历
        ·层序遍历（迭代法）
9.二叉树的定义：
链式存储：
struct TreeNode{
    int val;//结点值
    TreeNode*left;
    TreeNode*right;
    TreeNode(int x):val(x),left(NULL),right(NULL){};
}
morris遍历是⼆叉树遍历算法的超强进阶算法，morris遍历可以将⾮递归遍历中的空间复杂
度降为O(1)
如果需要遍历整颗树，递归函数就不能有返回值。如果需要遍历某⼀条固定路线，递归函数
就⼀定要有返回值！
