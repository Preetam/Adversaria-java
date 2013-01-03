import java.util.*;
import java.io.*;
import java.lang.Runtime;

public class Adversaria {

	static void create(String fileName) {
		advs_buffer buf = new advs_buffer(null, null);
		write(fileName, buf);
	}

	static void write(String fileName, advs_buffer buf) {
		try {
			FileOutputStream fileOut = new FileOutputStream(fileName);
			ObjectOutputStream out = new ObjectOutputStream(fileOut);
			out.writeObject(buf);
			out.close();
			fileOut.close();
		}

		catch (IOException i) {
			i.printStackTrace();
		}
	}

	static advs_buffer open(String fileName) {
		advs_buffer tmp = null;

		try {
			FileInputStream fileIn = new FileInputStream(fileName);
			ObjectInputStream in = new ObjectInputStream(fileIn);
			tmp = (advs_buffer)in.readObject();
			in.close();
			fileIn.close();

			return tmp;
		}

		catch (Exception i) {
			i.printStackTrace();
		}

		return null;
	}

	static void insert(String fileName, int timestamp, float inBytes, float outBytes) {
		advs_buffer buf = open(fileName);
		float[] val = {inBytes, outBytes};
		buf.put(timestamp, val);
		write(fileName, buf);
	}

	public static void main(String[] args) {
		switch (args[0]) {
			case "create": {
				if(args.length > 1)
					create(args[1]);
				else
					System.out.println("Need a file name.");
				break;
			}

			case "insert": {
				insert(args[1], Integer.parseInt(args[2]), Float.parseFloat(args[3]), Float.parseFloat(args[4]));
				break;
			}

			case "export": {
				open(args[1]).print();
				break;
			}

			default: {
				System.out.println("\nusage: java -jar adversaria.jar {function} {file} {data}");
				System.out.println("\nFunctions:\n");
				System.out.println("  create\tCreate a new storage file");
				System.out.println("  insert\tInsert a new data point");
				System.out.println("  export\tPrint as JSON\n");
				break;
			}
		}
//		Runtime runtime = Runtime.getRuntime();
//		System.out.println("Currently using " + runtime.totalMemory() / 1000000 + " MBytes of RAM.");
	}
}
