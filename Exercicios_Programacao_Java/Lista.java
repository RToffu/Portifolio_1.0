
public class Lista<T> {
	//NODE
	 class Node{
		public Filme data;
		public Node next;	
		
		Node(Filme data){
			this.data = data;
			next = null;
		}
	}//END_NODE
	public  int countComp;
	public  int countMov;
	public Node headN;
   public Node sorted;
	
	//CON
	public Lista() {
		headN = null;
		countComp = 0;
		countMov = 0;
	}//END_CON
	
	public int countCompPrint() 
	{
		return countComp;
	}
	
	public int countMovPrint() {
		return countMov;
	}
	
	public void push(Filme data)
	{
		Node new_node = new Node(data);
		new_node.next = headN;
		headN = new_node;
	}
	
	public void append(Filme data)
	{
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
	
	public int getNumElements() {
		Node temp = headN;
		int count = 0;
		
		while(temp != null) 
		{
			count++;
			temp = temp.next; 
		}
		
		return count;
	}
	/**
	 * ####################
	 * ## SELECTION_SORT ##
	 * ####################
	 */
	public void sortSelection() 
	{
		Node temp = headN;
		while(temp != null)
		{
			Node min = temp;
			Node r = temp.next;
				while(r != null) {
					if((int)(min.data.getOgTitle()).charAt(0) > (int)(r.data.getOgTitle()).charAt(0)) {
						min = r;
						countComp++;
					}else if((int)(min.data.getOgTitle()).charAt(0) == (int)(r.data.getOgTitle()).charAt(0)){
						if((int)(min.data.getOgTitle()).charAt(1) > (int)(r.data.getOgTitle()).charAt(1)) 
							min = r;
						countComp += 3;
					}else{	countComp += 2; }
					r = r.next;
				}
			countMov++;
			Filme x = temp.data;
			temp.data = min.data;
			min.data = x;
			temp = temp.next;
		}
		
	}
   
	/**
	 * 	####################
	 *  ## INSERTION_SORT ##
	 *  ####################
	 */
	
   public void sortInsertion(){
      sorted = null;
      Node temp = headN;
      while(temp != null)
      {
        Node prox = temp.next;
        sortedInsert(temp);
        temp = prox;
      }
      headN = sorted;
   }
   
   private void sortedInsert(Node newnode) 
    {
          
        
        if (sorted == null || sorted.data.getReleaseDate().compareTo(newnode.data.getReleaseDate()) >= 0) 
        {
            newnode.next = sorted;
            sorted = newnode;
        }
        else 
        {
            Node current = sorted;
           
            while (current.next != null && current.next.data.getReleaseDate().compareTo(newnode.data.getReleaseDate()) < 0) 
            {
                current = current.next;
            }
            newnode.next = current.next;
            current.next = newnode;
        }
    }//END INSERTION_SORT
	
	 public void printList()
	    {
	        Node tnode = headN;
	        while (tnode != null)
	        {
	            System.out.println(tnode.data+" ");
	            tnode = tnode.next;
	        }
	    }
	
	
}
