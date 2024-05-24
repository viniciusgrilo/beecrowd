import java.util.*;

public class Main
{
	public static void main(String[] args) {
		Scanner scan = new Scanner(System.in);
		
		int N = Integer.parseInt(scan.nextLine()), diamonds;
		String entrada;
		
		
		for(int i = 0; i < N; i++){
		    diamonds = 0;
		    entrada = scan.nextLine();
		    Stack<Character> stack = new Stack<Character>();
    		
    		for(int j = 0; j < entrada.length(); j++){
    		    switch(entrada.charAt(j)){
    		        
    		        case '<':
    		            stack.push('<');
                        break;    
                            
    		        case '>':
    		            if(!stack.isEmpty()){
    		                stack.pop();
    		                diamonds++;
    		            }
    		            
    		            break;


    		    }
    		    
    		   
    		}
        
            System.out.println(diamonds);
	    
    	}
	}
}
