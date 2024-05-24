import java.util.*;

public class Main
{
    
    public static int hash(int v, int M){
        int endereco = -1;
        
        if(M > 0){
            endereco = v % M;
            return endereco;
        }
        return endereco;
        
    }
    
    
    
	public static void main(String[] args) {
		
		int[][] tabelaHash;
		int M = 0, C = 0, casos = 0, end = 0, value = 0;
        Scanner scan = new Scanner(System.in);
        String[] entrada = null;
        int[] ultimo;
        
        casos = Integer.parseInt(scan.nextLine());
        
        
        for(int i = 0; i < casos; i++){
            
                
            
            entrada = scan.nextLine().split(" ");
            
            M = Integer.parseInt(entrada[0]);
            C = Integer.parseInt(entrada[1]);
            
            
            
            tabelaHash = new int[M][200];
            ultimo = new int[M];
            
            for(int y = 0; y < M; y++){
                for(int x = 0; x < 200; x++){
                    tabelaHash[y][x] = 0;
                }
            }
            
            for(int k = 0; k < M; k++)
                ultimo[k] = 0;
                
            entrada = scan.nextLine().split(" ");
            
            for(int j = 0; j < C; j++){
                
                end = hash(Integer.parseInt(entrada[j]), M);
                value = Integer.parseInt(entrada[j]);
                
                tabelaHash[end][ultimo[end]] = value;
                ultimo[end]++;
                
            }
            
            
            for(int l = 0; l < M; l++){
                
                System.out.print(l + " -> ");
                
                for(int o = 0; o < 200; o++){
                
                    if(tabelaHash[l][o] != 0)
                        System.out.print(tabelaHash[l][o] + " -> ");
                    else
                        break;
                    
                }
                
                System.out.println("\\");
                
            }
            
            if(i != casos - 1)
                System.out.println();

        }
                
                
            

    }
        
 
}