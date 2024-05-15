package Linked_List;

import Linked_List.Node;

public class myLinkedList<T extends Comparable<T>>{
    protected Node<T> head;
    public int size;

    public myLinkedList(){}
    
    public myLinkedList(){
        head=new Node<T>();
        size=0;
    }

    public void insert(int index,T data){
        if(index>size||index<0){
            return;
        }
        Node<T>newnode=new Node<T>(data);
        
        if(head==null){
            head=newnode;
            size++;
            return;
        }

        if (index == 0) {
            newnode.next = head.next;
            if (head.next != null) {
                head.next.prev = newnode;
            }
            head.next = newnode;
            newnode.prev = head;
        } else {
            Node<T> temp = head.next;//头节点是一个哑节点
            for (int i = 0; i < index - 1; i++) {
                temp = temp.next;
            }
            newnode.next = temp.next;
            if (temp.next != null) {
                temp.next.prev = newnode;
            }
            temp.next = newnode;
            newnode.prev = temp;
        }
        size++;
    }
    public boolean contains(T data){
        if(head==null)return false;
        Node<T> temp=head;
        while(temp!=null){
            if(temp.data=data)return true;
            temp=temp.next;
        }
        return false;
    }

    public void delete(int index){
        if(index>size)return;

        if(index==0){
            head=head.next;
            return;
        }
        if(index==1){
            head.next=null;
            return;
        }
        Node<T>temp=head;
        for(int i=0;i<index;i++){
            temp=temp.next;
        }
        temp=temp.next;
        if(temp.next==null){
            temp.prev.next=null;
            return;
        }else{
            temp.prev.next=temp.next;
            temp.next.prev=temp.prev;
        }
    }
}
