import java.io.InputStreamReader;
import java.io.BufferedReader;
class CFEVER3
{
	public static void main(String[] args) throws Exception{
		BufferedReader br = new BufferedReader(new InputStreamReader(System.in));
		StringBuffer sf=new StringBuffer();
		int t = Integer.parseInt(br.readLine().trim());
		while(t-- != 0){
			sf.append(Integer.toString(Integer.parseInt(br.readLine()),9)+"\n");
		}
		System.out.println(sf);
	}
}
