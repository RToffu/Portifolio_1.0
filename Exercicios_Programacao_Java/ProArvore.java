	public class ProArvore {
		public class Arvore<t>{
			public class Node{
				int key;
				Node left, right;
				
				public Node(int item)
				{
					key = item;
					left = right = null;
				}
			}//END_NODE
		
			public Node root;
			
			public Arvore(){
				root = null;
			}
			//pesquisar
			//insercao
			public void insercao(int num){ root = insercaoRec(root, num); }
			public void insercaoRec(Node root, int num){
				//ponteiro auxiliar
				
				//arvore vazia
				if(root == null)
				{
					root = new Node(num);
					return;
				}
				//pesquisa na arvore ate NULL
				if(num < root.key)
					root.left = insercaoRec(root.left, num);
				else if(key > root.key)
					root.right = insercaoRec(root.right, num);
				
				return root;
			}//END_INSERCAO
			//print_infixo
			void printInf(Node root)
			{
				if(root != null)
				{
					printInf(root.left);
					System.out.println(root.key);
					printInf(root.right);
				}
			}//END_PRINT_INFIXO
			//print_pref
			void printPref(Node root)
			{
				if(root != null)
				{
					System.out.println(root.key);
					printInf(root.left);
					printInf(root.right);
				}
			}//END_PRINT_PREFIXO
			//print_posf
			void printPosf(Node root)
			{
				if(root != null)
				{
					printInf(root.left);
					printInf(root.right);
					System.out.println(root.key);
				}
			}//END_PRINT_POSFIXO
			
			
			
		}//END_ARVORE
	public static void Main(String []args){
		//n -> inteiro numero de instancias
		//t -> numero de elementos a serem inseridos
		//array -> inteiros que serao inseridos na arvore
	}//ENDMAIN
	}