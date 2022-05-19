
public class ListaEncadeada<T> {
	//NODE
	public class Node{
		public Film data;
		public Node next;	
		
		Node(Film data){
			this.data = data;
			next = null;
		}
	}//END_NODE
	
	public Node headN;
	
	public ListaEncadeada() {
		headN = null;
	}
	
	public void append(Film data) {
		Node new_node = new Node(data);
		
		if(headN == null) {
			headN = new Node(data);
			return;
			}
		
		new_node.next = null;
		
		Node last = headN;
			while(last.next != null)
				last = last.next;
			last.next = new_node;
			return;
	}
	
	 public void printList()
	    {
	        Node tnode = headN;
	        while (tnode != null)
	        {
	            System.out.print(tnode.data+" ");
	            tnode = tnode.next;
	        }
	    }
	
	
}
