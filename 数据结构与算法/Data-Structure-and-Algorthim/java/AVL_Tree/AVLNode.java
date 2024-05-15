package AVL_Tree;

class AVLNode<T extends Comparable<T>> implements Comparable<AVLNode<T>> {
    //AVLNode是一个泛型类，表示AVL树中的节点，它要求存储在节点中的数据类型T必须实现Comparable接口，这是因为AVL树需要能够比较其节点的值来维持顺序。
        protected T data;
        protected int height;
        protected AVLNode<T>lchild,rchild;

        AVLNode(T data){
            this.data=data;
            height=1;
            lchild=null;
            rchild=null;
        }
        
        public boolean equals(AVLNode<T> e){
            return data.equals(e.data);
        }

        public String toString(){
            String str="["+data.toString()+","+height+"]";
            return str;
        }

        @Override
        public int compareTo(AVLNode<T>o){
            //compareTo(tree.AVLNode<T> o)：这是Comparable接口的一个方法，它需要被实现，以便可以比较两个节点。
            return data.compareTo(o.data);
        }
    
}
