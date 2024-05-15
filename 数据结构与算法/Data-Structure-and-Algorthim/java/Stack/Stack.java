package Stack;

import Stack.Node;

public class Stack<T extends Comparable<T>>{
    private Node<T> head;
    
    public Stack(){
        head=new Node<T>();
    }

    public void push(T data){
        Node<T> newnode=new Node<T>(data);
        if(head==null){
            head=newnode;
            return;
        }
        newnode.next=head;
        head=newnode;
        
        return;
    }

    public void pop(){
        if(head==null){
            return;
        }
        head=head.next;
        return;
    }

    public T getTop(){

        return head.data;
    }
}
