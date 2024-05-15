package Stack;

public class Node<T extends Comparable<T>> implements Comparable<Node<T>> {
    protected T data;
    protected Node<T> next;

    Node(){}
    Node(T data){
        this.data=data;
        next=null;
    }

    public boolean equals(Node<T> e){
        return data.equals(e.data);
    }

    public String toString(){
        String str="["+data.toString()+"]";
        return str;
    }

    @Override
    public int compareTo(Node<T> o){
        return data.compareTo(o.data);
    }
}


