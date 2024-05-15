package AVL_Tree;

public class test {
    public static void main(String[] args){
        AVLTree<Integer> tree = new AVLTree<>();

        // 插入操作
        System.out.println("Inserting values...");
        tree.add(10);
        tree.add(20);
        tree.add(30);
        tree.add(40);
        tree.add(50);
        tree.add(25);
        tree.add(35);


        // 打印树结构
        System.out.println("Tree after insertions:");
        tree.Inprint();

        // 删除操作
        System.out.println("Deleting values...");
        tree.delete(30);

        // 打印树结构
        System.out.println("Tree after deletions:");
        tree.Inprint();
    }
}
