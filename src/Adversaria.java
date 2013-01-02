import java.util.*;
import java.io.*;
import java.lang.Runtime;

class AdversariaObj implements java.io.Serializable {
	static final long serialVersionUID = -6724870319916642357l;
	private SortedMap primaryMap;
	private SortedMap secondaryMap;

	public AdversariaObj(SortedMap primary, SortedMap secondary) {
		primaryMap = primary;
		secondaryMap = secondary;
	}

	public int getSize() {
		return primaryMap.size() + secondaryMap.size();
	}
}

public class Adversaria {
	public static void main(String[] args) {
		SortedMap<Integer, Float[]> primary = new TreeMap<Integer, Float[]>();
		SortedMap<Integer, Float[]> secondary = new TreeMap<Integer, Float[]>();

		AdversariaObj myObj = new AdversariaObj(primary, secondary);

		try {
			FileOutputStream fileOut = new FileOutputStream("serialized");
			ObjectOutputStream out = new ObjectOutputStream(fileOut);
			out.writeObject(myObj);
			out.close();
			fileOut.close();
		}
		catch (IOException i) {
			i.printStackTrace();
		}

		AdversariaObj tmp = null;
		try {
			FileInputStream fileIn = new FileInputStream("adsv.db");
			ObjectInputStream in = new ObjectInputStream(fileIn);
			tmp = (AdversariaObj)in.readObject();
			in.close();
			fileIn.close();
		}

		catch (Exception i) {
			i.printStackTrace();
		}

		System.out.println("Size: " + tmp.getSize());
//		Iterator iterator = map.keySet().iterator();
//		while(iterator.hasNext()) {
//			Object key = iterator.next();
//			System.out.println(key + " => " + Arrays.toString((float[])(map.get(key))));
//		}
		Runtime runtime = Runtime.getRuntime();
		System.out.println("Currently using " + runtime.totalMemory() / 1000000 + " MBytes of RAM.");
	}
}
