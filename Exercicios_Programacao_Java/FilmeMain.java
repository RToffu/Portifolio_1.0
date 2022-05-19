
public class FilmeMain {

	public static void main(String[] args) {
		ListaEncadeada<Film> lista = new ListaEncadeada<Film>();
		
		
		Film filme = new Film();
		String str = MyIO.readLine();
		filme.ler(str);
		lista.append(filme);
		
		lista.printList();
	}

}
