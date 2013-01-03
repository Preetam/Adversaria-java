import java.util.*;
import java.io.*;
import java.lang.Runtime;

class advs_buffer implements java.io.Serializable {
	static final long serialVersionUID = -6724870319916642357l;
	private SortedMap primaryMap;
	private SortedMap secondaryMap;

	public advs_buffer(SortedMap primary, SortedMap secondary) {
		if(primary == null)
			primaryMap = new TreeMap<Integer, Float[]>();
		else
			primaryMap = primary;
		if(secondary == null)
			secondaryMap = new TreeMap<Integer, Float[]>();
		else
			secondaryMap = secondary;
	}

	public int getSize() {
		return primaryMap.size() + secondaryMap.size();
	}

	public void print() {
		Iterator iterator = secondaryMap.keySet().iterator();
		while(iterator.hasNext()) {
			Object key = iterator.next();
			System.out.println(key + " => " + Arrays.toString((float[])(secondaryMap.get(key))));
		}
		iterator = primaryMap.keySet().iterator();
		while(iterator.hasNext()) {
			Object key = iterator.next();
			System.out.println(key + " => " + Arrays.toString((float[])(primaryMap.get(key))));
		}
	}

	public void put(int key, float[] val) {
		primaryMap.put(key, val);
	}
}
