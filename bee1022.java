import java.util.*;

public class Main
{    
    static int mdc(int a, int b)
        {
        	if(a<0)
        		a = -a;
        	if(b<0)
        		b = -b;
        	if(a%b == 0)
        		return b;
        	else
        		return mdc(b,a%b);
        }

	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		
		int N = Integer.parseInt(scan.nextLine());
		
		for(int i = 0; i < N; i++){
		    String[] entrada = scan.nextLine().split(" ");
		
    		int N1 = Integer.parseInt(entrada[0]);
    		int D1 = Integer.parseInt(entrada[2]);
    	    int N2 = Integer.parseInt(entrada[4]);
    	    int D2 = Integer.parseInt(entrada[6]);
    	    
    	    int nRes = 0, dRes = 0;
    
    		switch(entrada[3]){
    		    
    		    case "+":
    		        nRes = (N1*D2 + N2*D1);
    		        dRes = (D1*D2);
    		        System.out.print(nRes + "/" + dRes + " = ");
    		        break;
    		        
    		    case "-":
    		        nRes = (N1*D2 - N2*D1);
    		        dRes = (D1*D2);
    		        System.out.print(nRes + "/" + dRes + " = ");
    		        break;
    		    
    		    case "*":
    		        nRes = (N1*N2);
    		        dRes = (D1*D2);
    		        System.out.print(nRes + "/" + dRes + " = ");
    		        break;
    		        
    		    case "/":
    		        nRes = (N1*D2);
    		        dRes = (N2*D1);
    		        System.out.print(nRes + "/" + dRes + " = ");
    		        break;
    		    
    		}
    		
    		int div  = mdc(nRes, dRes);
    		
    		System.out.printf("%d/%d\n", nRes/div, dRes/div);
    		
    		
		}		
	}
}