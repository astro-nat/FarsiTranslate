/*
* This program translates the "English" translation 
* of the Farsi alphabet into English.

Credit: Natalie Cluck

*/

import java.util.*;
import java.util.Enumeration;

class FarsiTranslate {
	public static void main(String args[]) {
		// create hashtable with farsi alphabet
		Hashtable farsi = new Hashtable();
		farsi.put(0x0624, new String("A"));
		farsi.put(0x200C, new String("B"));
		String elem;
		Enumeration farsi_letters;
	
		farsi_letters = farsi.keys();
	
		// prints elements in hashtable
		while(farsi_letters.hasMoreElements()) {
			 elem = (String) farsi_letters.nextElement();
			 System.out.println(elem + ": " + farsi.get(elem));
		  }        
		  System.out.println();
		  
		for(int i = 0; i < farsi.size(); i++)
			System.out.print("Elem: " + farsi_letters[i]);
			
			
}
}
