package Linked_List;

import Linked_List.Node;

public class Node<T extends Comparable<T>> implements Comparable<Node<T>> {
    public T data;
    public Node<T> next;
    protected Node<T> prev;

    Node(){}

    Node(T data){
        this.data=data;
        next=null;
        prev=null;
    }

    public boolean equals(Node<T>e){
        return data.equals(e.data);
    }

    public String toString(){
        String str="["+data.toString()+"]";
        return str;
    }

    public int compareTo(Node<T> o){
        return data.compareTo(o.data);
    }
}
