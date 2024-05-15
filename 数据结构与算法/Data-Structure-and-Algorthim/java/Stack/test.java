package Stack;

public class test {
    public static void main(String args[]){
        Stack<Integer>mystk=new Stack<Integer>();

        mystk.push(1);
        mystk.push(2);
        mystk.push(3);

        System.out.println(mystk.getTop());

        mystk.pop();

        System.out.println(mystk.getTop());
    }
}
