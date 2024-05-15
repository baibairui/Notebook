package AVL_Tree;


public class AVLTree<T extends Comparable<T>> {
    protected AVLNode<T> root;

    public AVLTree(){
        this.root=null;
    }

    public int getHeight(AVLNode<T>Node){
        return (Node==null)?0:Node.height;
    }

    public int max(int a,int b){
        return a>b?a:b;
    }
    //获取节点的平衡因子bf
        //bf=0,平衡；bf<0,右子树更高；bf>0,左子树更高;
    protected int getBalance(AVLNode<T> Node){
        return (Node==null)?0:getHeight(Node.lchild)-getHeight(Node.rchild);
    }

    //判断树是否平衡
    public boolean check(){
        return isBalanced(root);
    }
    private boolean isBalanced(AVLNode<T> Node){
        if(Node==null)return true;
        //如果节点的平衡因子绝对值大于1则说明树没平衡
        int balanceFactor=Math.abs(getBalance(Node));
        if(balanceFactor>1)return false;
        return isBalanced(Node.lchild)&&isBalanced(Node.rchild);
    }

    //LL型调整：LL型指的是向左子树中添加了一个左子节点导致树不平衡，这种情况需要进行右旋转
    private AVLNode<T> turnLL(AVLNode<T> Node){
        AVLNode<T>X=Node.lchild;
        
        Node.lchild=X.rchild;
        X.rchild=Node;

        X.height=max(getHeight(X.lchild),getHeight(X.rchild))+1;
        Node.height=max(getHeight(Node.lchild),getHeight(Node.rchild))+1;

        return X;
    }
    //RR型调整：RR型指的是向右子树中添加了一个右子节点导致树不平衡，这种情况需要进行左旋转
    private AVLNode<T> turnRR(AVLNode<T> Node){
        AVLNode<T>X=Node.rchild;

        Node.rchild=X.lchild;
        X.lchild=Node;

        X.height=max(getHeight(X.lchild),getHeight(X.rchild))+1;
        Node.height=max(getHeight(Node.lchild),getHeight(Node.rchild))+1;

        return X;
    }

    //LR型调整：LR型调整是AVL树中的一种调整情形，它是针对于在某个节点的左子节点的右子树中插入一个新节点而导致的不平衡。
    private AVLNode<T> turnLR(AVLNode<T>Node){
        Node.lchild=turnRR(Node.lchild);
        Node=turnLL(Node);
        return Node;
    }

    //RL型调整
    private AVLNode<T> turnRL(AVLNode<T>Node){
        Node.rchild=turnLL(Node.rchild);
        Node=turnRR(Node);
        return Node;
    }

    public void add(T Key){
       root= add(Key,root);
    }
    private AVLNode<T> add(T key, AVLNode<T> node) {
        if (node == null) {
            return new AVLNode<>(key);
        }
        int cmp = key.compareTo(node.data);
        if (cmp < 0) {
            node.lchild = add(key, node.lchild);
        } else if (cmp > 0) {
            node.rchild = add(key, node.rchild);
        } else {
            // 键值相等，不插入重复数据
            return node;
        }

        // 更新节点高度
        node.height = 1 + Math.max(getHeight(node.lchild), getHeight(node.rchild));

        // 获取平衡因子并进行平衡调整
        int balance = getBalance(node);
        if (balance > 1) {
            if (getBalance(node.lchild) >= 0) {
            return turnLL(node); // LL情况
        } else {
            return turnLR(node); // LR情况
        }
        } else if (balance < -1) {
            if (getBalance(node.rchild) <= 0) {
                return turnRR(node); // RR情况
            } else {
            return turnRL(node); // RL情况
                    }
        }

    return node; // 无需调整，返回当前节点
    }

    public AVLNode<T> findmin(AVLNode<T>node){
        if(node.lchild==null)return node;
        return findmin(node.lchild);
    }
    public void delete(T key){
        root=delete(key,root);
    }

    private AVLNode<T> delete(T key,AVLNode<T>node){
        if(node==null)return null;
        int com=key.compareTo(node.data);

        if(com<0){
            delete(key, node.lchild);
        }else if(com>0){
            delete(key, node.rchild);
        }else if(node.lchild!=null&&node.rchild!=null){
            AVLNode<T>newnode=findmin(node.rchild);
            node.data=newnode.data;
            node.rchild = delete(newnode.data, node.rchild);
        }else if (node.lchild != null && node.rchild == null) {
            return node.lchild; // 直接返回左子节点
        } else if (node.lchild == null && node.rchild != null) {
            return node.rchild; // 直接返回右子节点
        }

        // 获取平衡因子并进行平衡调整
        int balance = getBalance(node);
        if (balance > 1) {
            if (getBalance(node.lchild) >= 0) {
            return turnLL(node); // LL情况
        } else {
            return turnLR(node); // LR情况
        }
        } else if (balance < -1) {
            if (getBalance(node.rchild) <= 0) {
                return turnRR(node); // RR情况
            } else {
            return turnRL(node); // RL情况
                    }
        }

    return node; // 无需调整，返回当前节点
    }
    public void Inprint(){
        InorderprintTree(root);
    }
    private void InorderprintTree(AVLNode<T> Node){
        if(Node!=null){
        InorderprintTree(Node.lchild);
        System.out.println(Node.data);
        InorderprintTree(Node.rchild);
        }
        
    }
    }
