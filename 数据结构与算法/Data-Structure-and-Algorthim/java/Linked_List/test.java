package Linked_List;


public class test {
    public static void main(String args[]){
        myLinkedList<Integer>list=new myLinkedList<Integer>();

        list.insert(0,1);
        list.insert(0,2);
        list.insert(0,3);
        list.insert(1,4);

        Node<Integer>temp=list.head.next;
        while(temp!=null){
            System.out.println(temp.data);
            temp=temp.next;
        }
    }
}  
