import java.net.InetAddress;
import java.net.MalformedURLException;
import java.net.URL;
import java.net.UnknownHostException;

public class test {
  public static void main(String[] args) throws UnknownHostException, MalformedURLException, InterruptedException {
      Thread t1=new Thread(new Myrunnable(){
        @Override
        public void run() {
           for(int i=0;i<=20;i++){
              try{
                Thread.sleep(1000);
              }catch(InterruptedException e){
                  e.printStackTrace();
              }
              System.out.println("xmum:"+i);
           }
        }
      });
      t1.start();
      for(int i=0;i<=20;i++){
        try{
          Thread.sleep(1000);
        }catch(InterruptedException e){
          e.printStackTrace();
        }
        System.out.println("xmu:"+i);
        if(i>5){
          Thread.yield();
        }
      }

  }
}

class Myrunnable implements Runnable{
    public void run(){}
}
